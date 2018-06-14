/******************************************
 * Adam Bajguz
 ******************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

#define ARRAY_3D_PRINT 0
#define USE_SKIPPING_METHOD 1

#define FILE_ID "0"

#define MAKE_FILENAME(name) name FILE_ID ".txt"
#define INPUT_FILENAME MAKE_FILENAME("in")
#define OUTPUT_FILENAME "out.txt"
#define ANSWER_FILENAME MAKE_FILENAME("out")


#define DATA_STRUCT data
#define SOLDIERS_STRUCT soldiers

#define MAX_FOOD DATA_STRUCT.max_food
#define MAX_FOOD_REF DATA_STRUCT->max_food

#define MAX_ENT DATA_STRUCT.max_entertainment
#define MAX_ENT_REF DATA_STRUCT->max_entertainment

#define SOLDIERS_NUM DATA_STRUCT.soldiers_num
#define SOLDIERS_NUM_REF DATA_STRUCT->soldiers_num


#define OUTPUT DATA_STRUCT.output
#define OUTPUT_REF DATA_STRUCT->output

#define SOLDIERS DATA_STRUCT.SOLDIERS_STRUCT
#define SOLDIERS_REF DATA_STRUCT->SOLDIERS_STRUCT

#define SEL_SOLDIERS OUTPUT.sel_soldiers
#define SEL_SOLDIERS_REF OUTPUT_REF.sel_soldiers

#define ARRAY_GET(REF, x) ((REF) + (x))

#define STRENGTH_RESULTS DATA_STRUCT.strength_results
#define STRENGTH_RESULTS_REF DATA_STRUCT->strength_results

#define RESULTS(x, y, z) ((STRENGTH_RESULTS_REF) + (MAX_FOOD_REF + 1)*(MAX_ENT_REF + 1)*(x) + (MAX_ENT_REF + 1)*(y) + (z))
#define RESULTS_LENGTH (SOLDIERS_NUM_REF + 1) * (MAX_FOOD_REF + 1) * (MAX_ENT_REF + 1)

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

struct t_soldier {
    uint8_t id;
    uint32_t strength, food, entertainment;
};

struct t_output {
    uint32_t max_strength;
    uint8_t last_soldier_index;
    uint8_t *sel_soldiers;
};

struct t_data {
    uint16_t max_food, max_entertainment;
    uint8_t soldiers_num;
    struct t_soldier *soldiers;
    struct t_output output;

    uint32_t *strength_results;
};

void read_file(struct t_data *const data) __attribute__ ((always_inline));

void algorithm(struct t_data *const data) __attribute__ ((always_inline));

void write_output_to_file(const struct t_data *const data) __attribute__ ((always_inline));

void read_answer_file() __attribute__ ((always_inline));

int main() {
    clock_t exec_begin_all = clock();

    struct t_data data;
    OUTPUT.last_soldier_index = 0;
    read_file(&data);

    clock_t exec_begin_algo = clock();
    algorithm(&data);
    clock_t exec_end_algo = clock();

    write_output_to_file(&data);

    clock_t exec_end_all = clock();
    double exec_time_all = ((double) (exec_end_all - exec_begin_all)) / CLOCKS_PER_SEC;
    double exec_time_algo = ((double) (exec_end_algo - exec_begin_algo)) / CLOCKS_PER_SEC;


    printf("\n    OUTPUT: %d", OUTPUT.max_strength);
    printf("\n            ");

    if(OUTPUT.max_strength) {
        uint8_t lsi = OUTPUT.last_soldier_index - 1;
        do
            printf("%d ", *ARRAY_GET(SEL_SOLDIERS, lsi));
        while (lsi--);
        printf("\n");
    }

    read_answer_file();

    printf("\nSTATISTICS:\n");
    printf("   Execution time: %f seconds.\n", exec_time_all);
    printf("   Execution time without operations on files: %f seconds.\n", exec_time_algo);

    free(SOLDIERS);
    free(SEL_SOLDIERS);
    free(STRENGTH_RESULTS);

    return 0;
}

void read_file(struct t_data *const data) {
    FILE *in = fopen(INPUT_FILENAME, "rt");
    if (in) {
        fscanf(in, "%hu %hu %u", &MAX_FOOD_REF, &MAX_ENT_REF, &SOLDIERS_NUM_REF);

        SOLDIERS_REF = malloc(sizeof(*SOLDIERS_REF) * SOLDIERS_NUM_REF);

#if USE_SKIPPING_METHOD == 1
        register uint8_t next_i = 0;
        uint32_t tmp_strength, tmp_food, tmp_ent;
        register uint8_t end = SOLDIERS_NUM_REF;

#else
        register uint8_t end = SOLDIERS_NUM_REF;
#endif

        for (register uint8_t i = 0; i < end; ++i)
        {
#if USE_SKIPPING_METHOD == 1
            fscanf(in, "%u %u %u", &tmp_strength, &tmp_food, &tmp_ent);

            if(tmp_food > MAX_FOOD_REF || tmp_ent > MAX_ENT_REF)
                --SOLDIERS_NUM_REF;
            else {
                ARRAY_GET(SOLDIERS_REF, next_i)->id = i+1;
                ARRAY_GET(SOLDIERS_REF, next_i)->strength = tmp_strength;
                ARRAY_GET(SOLDIERS_REF, next_i)->food = tmp_food;
                ARRAY_GET(SOLDIERS_REF, next_i)->entertainment = tmp_ent;
                ++next_i;
            }
#else
              fscanf(in, "%u %u %u", &ARRAY_GET(SOLDIERS_REF, i)->strength, &ARRAY_GET(SOLDIERS_REF, i)->food,
                 &ARRAY_GET(SOLDIERS_REF, i)->entertainment);
#endif
        }

        SEL_SOLDIERS_REF = malloc(sizeof(*SEL_SOLDIERS_REF) * SOLDIERS_NUM_REF);
        STRENGTH_RESULTS_REF = calloc(RESULTS_LENGTH, sizeof(*STRENGTH_RESULTS_REF));

        fclose(in);
    } else {
        printf("Error reading from %s!", INPUT_FILENAME);
        exit(1);
    }
}

void algorithm(struct t_data *const data) {
    register uint8_t soldier = 1;
    register uint16_t food, ent;

    register int32_t food_test, ent_test;

    // Zaczynamy od n = 1, bo pierwsza plaszczyzna jest wypelniona zerami
    for (register uint8_t prev_soldier = 0; soldier <= SOLDIERS_NUM_REF; ++prev_soldier, ++soldier) {
        for (food = 1; food <= MAX_FOOD_REF; ++food) {
            for (ent = 1; ent <= MAX_ENT_REF; ++ent) {

                // n-1 poniewaz iterujemy od 1 ze wzgledu na strukture results (dodatkowe 3 plaszczyzny wypelnione zerami)
                food_test = food - ARRAY_GET(SOLDIERS_REF, prev_soldier)->food;
                ent_test = ent - ARRAY_GET(SOLDIERS_REF, prev_soldier)->entertainment;

                // Jezeli zolnierz za duzo wymaga to kopiujemy poprzedniego zolnierza
                if (food_test < 0 || ent_test < 0)
                    *RESULTS(soldier, food, ent) = *RESULTS(prev_soldier, food, ent);
                else  // W przeciwnym wypadku sprawdzamy go maxem!
                    // Tzn jezeli nie oplaca sie wziac, to przepisujemy poprzedniego (pierwszy argument Max jest wiekszy)
                    // a jezeli oplaca sie go wziac, to go wpisujemy do naszych ziomkiw (drugi argument Max jest wiekszy)
                    *RESULTS(soldier, food, ent) = max(*RESULTS(prev_soldier, food, ent),
                                                       ARRAY_GET(SOLDIERS_REF, prev_soldier)->strength +
                                                       *RESULTS(prev_soldier, food_test, ent_test));
            }
        }
    }

    // Zaczynamy wyznaczanie zolnierzy od konca
    soldier = SOLDIERS_NUM_REF;
    food = MAX_ENT_REF, ent = MAX_FOOD_REF;

    OUTPUT_REF.max_strength = *RESULTS(soldier, ent, food);
    if(OUTPUT_REF.max_strength)
        while (soldier > 0) {
            if (*RESULTS(soldier, ent, food) != *RESULTS(soldier - 1, ent, food)) {
                ent -= ARRAY_GET(SOLDIERS_REF, soldier - 1)->food;
                food -= ARRAY_GET(SOLDIERS_REF, soldier - 1)->entertainment;

#if USE_SKIPPING_METHOD == 1
                *ARRAY_GET(SEL_SOLDIERS_REF, OUTPUT_REF.last_soldier_index++) = ARRAY_GET(SOLDIERS_REF, soldier - 1)->id;
#else
                *ARRAY_GET(SEL_SOLDIERS_REF, OUTPUT_REF.last_soldier_index++) = soldier;
#endif
            }
            --soldier;
        }

#if ARRAY_3D_PRINT != 0
    for (uint8_t soldier = 1; soldier <= SOLDIERS_NUM_REF ; soldier++) {
        for (uint16_t food = 1; food <= MAX_FOOD_REF; food++) {
            for (uint16_t ent = 1; ent <= MAX_ENT_REF; ent++) {
                printf("%d ", *RESULTS(soldier, food, ent));
            }
            printf("\n");
        }
        printf("\n\n");
    }
#endif
}

void write_output_to_file(const struct t_data *const data) {
    FILE *out = fopen(OUTPUT_FILENAME, "wt");
    if (out) {
        fprintf(out, "%u\n", OUTPUT_REF.max_strength);

        if(OUTPUT_REF.max_strength) {
            uint8_t lsi = OUTPUT_REF.last_soldier_index - 1;
            do
                fprintf(out, "%d ", *ARRAY_GET(SEL_SOLDIERS_REF, lsi));
            while (lsi--);
        }

        fclose(out);
    } else
        printf("\nError writing to %s!\n", OUTPUT_FILENAME);
}

void read_answer_file() {
    FILE *in = fopen(ANSWER_FILENAME, "rt");
    uint32_t tmp;
    if (in) {
        fscanf(in, "%d", &tmp);

        printf("\n    ANSWER: %d", tmp);
        printf("\n            ");

        while (!feof(in)) {
            if (fscanf(in, "%d", &tmp) == 1)
                printf("%d ", tmp);
        }
        printf("\n");

        fclose(in);
    } else {
        printf("Error reading from %s!", ANSWER_FILENAME);
    }
}