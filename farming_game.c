// 2021/10/15
//
// Version 1.0.0 (2021-10-04)
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_SIZE 50
#define MAX_NUM_SEED_TYPES 26
#define LAND_SIZE 8
#define NO_SEED ' '
#define TRUE 1
#define FALSE 0

struct land {
    int is_watered;
    char seed_name;
};

struct seeds {
    char name;
    int amount;
};

struct farmer {
    int curr_col;
    int curr_row;
    char curr_dir;
};


// HINT: Will be using this function in stage 2!
void print_land(struct land farm_land[LAND_SIZE][LAND_SIZE], struct farmer cse_farmer);

// Provided functions use for game setup
struct farmer initialise_farmer(struct farmer cse_farmer);
void initialise_seeds(struct seeds seed_collection[MAX_NUM_SEED_TYPES]);
void initialise_land(struct land farm_land[LAND_SIZE][LAND_SIZE]);
void print_top_row(struct land farm_land[LAND_SIZE][LAND_SIZE], int row);
void print_farmer_row(struct land farm_land[LAND_SIZE][LAND_SIZE], 
                      struct farmer cse_farmer);

int main(void) {

    struct farmer cse_farmer = {};
    cse_farmer = initialise_farmer(cse_farmer);

    struct land farm_land[LAND_SIZE][LAND_SIZE];
    initialise_land(farm_land);

    struct seeds seed_collection[MAX_NUM_SEED_TYPES];
    initialise_seeds(seed_collection);

    printf("Welcome to CSE Valley, farmer!\n");
    printf("Congratulations, you have received 60 seeds.\n");
    printf("How many different seeds do you wish to have? ");
    //user type a number of how many seeds will have
    int num = 0;
    scanf("%d", &num);
    int daytime = 1;

    // TODO: Scan the number of different seeds here!
    // Note: Please remove all TODO's in your submission (including this comment)

    printf("Enter the names of the seeds to be given:\n");
    //while loop for seeds
    int intial = 0;
    while (intial < num) {
        scanf(" %c", &seed_collection[intial].name);
        seed_collection[intial].amount = 60/num;
        intial++;
        //the seeds are totally 60 amounts, need to divided by the number that user insert
        //the numbers of seeds that user have
    }

    printf("Game Started!\n");
    
    // TODO: When you start stage 1.2, you will need to replace the below
    // with a loop that reads and executes commands until EOF.

    char command;
    printf("Enter command: ");

    while (scanf("%c", &command) != EOF) {
        intial = 0;
        //enter command 'a' that print all the seeds
        if (command == 'a') {
            printf("  Seeds at your disposal:\n");
            while (intial < num) {
                printf("  - %d seed(s) with the name '%c'\n", 
                seed_collection[intial].amount, seed_collection[intial].name);
                intial++;
            }
            printf("Enter command: ");
        }

        //enter command 's' that print the unique seed that user enter
        if (command == 's') {
            char l;
            int loop = 0;
            scanf(" %c", &l);
            if (l < 'a' || l > 'z') {
                printf("  Seed name has to be a lowercase letter\n");
            }
            else {
                while (intial < num) {
                    if (l == seed_collection[intial].name) {
                        printf("  There are %d seeds with the name '%c'\n", 
                        seed_collection[intial].amount, seed_collection[intial].name);
                        loop = 1;
                        break;
                    }
                    intial++;
                }
                if (loop == 0) {
                    printf("  There is no seed with the name '%c'\n", l);
                }
            }
            printf("Enter command: ");
        }
        //enter the command 'l' that print the land it gives
        if (command == 'l') {
            print_land(farm_land, cse_farmer);
            printf("Enter command: ");
        }
        //enter the command '^' for moving up with restriction
        if (command == '^') {
            int boundary = 0;
            if (cse_farmer.curr_dir == '^') {    
                if (cse_farmer.curr_row > boundary) {
                    cse_farmer.curr_row--;
                }
            }
            //if the direction is not moving up then make it to be like this
            else {
                cse_farmer.curr_dir = '^';
            }
            printf("Enter command: ");
        }
        //enter the command 'v' for moving up with restriction
        if (command == 'v') {
            int length = 7;
            if (cse_farmer.curr_dir == 'v') {
                if (cse_farmer.curr_row < length) {
                    cse_farmer.curr_row++;
                }
            }
            //if the direction is not moving down then make it to be like this
            else {
                cse_farmer.curr_dir = 'v';
            }         
            printf("Enter command: ");
        }
        //enter the command '>' for moving up with restriction
        if (command == '>') {
            int length = 7;
            if (cse_farmer.curr_dir == '>') {    
                if (cse_farmer.curr_col < length) {
                    cse_farmer.curr_col++;
                }
            }
            //if the direction is not moving right then make it to be like this
            else {
                cse_farmer.curr_dir = '>';
            }  
            printf("Enter command: ");
        }

        //enter the command '<' for moving up with restriction
        if (command == '<') {
            int boundary = 0;
            if (cse_farmer.curr_dir == '<') {
                if (cse_farmer.curr_col > boundary) {
                    cse_farmer.curr_col--;
                }
            }
            //if the direction is not moving left then make it to be like this
            else {
                cse_farmer.curr_dir = '<';
            }
            printf("Enter command: ");
        }

        //enter the command 'o' that watering and planting unique seed on the land
        if (command == 'o') {
            char second_command;
            char plant;
            scanf(" %c", &second_command);
            int row = cse_farmer.curr_row;
            int col = cse_farmer.curr_col;
            //if command is "o w", then watering
            if (second_command == 'w') {
                int length = 7;
                int boundary = 0;
                if (cse_farmer.curr_dir == '^') {
                    if (cse_farmer.curr_row > boundary) {
                        farm_land[row - 1][col].is_watered = TRUE;
                    }        
                }

                if (cse_farmer.curr_dir == 'v') {
                    if (cse_farmer.curr_row < length) {
                        farm_land[row + 1][col].is_watered = TRUE;
                    } 
                }

                if (cse_farmer.curr_dir == '>') {    
                    if (cse_farmer.curr_col < length) {
                        farm_land[row][col + 1].is_watered = TRUE;
                    }
                }

                if (cse_farmer.curr_dir == '<') {
                    if (cse_farmer.curr_col > boundary) {
                        farm_land[row][col - 1].is_watered = TRUE;
                    }
                }               
            }
            //if command is "o p", then plant the unique seed
            if (second_command == 'p') {
                int length = 7;
                int boundary = 0;
                scanf(" %c", &plant);

                int i = 0;
                while (i < num) {
                    if (seed_collection[i].name == plant) {
                        if (cse_farmer.curr_dir == '^') {
                            if (cse_farmer.curr_row > boundary) {
                                farm_land[row - 1][col].seed_name = 
                                seed_collection[i].name;
                                seed_collection[i].amount--;
                            }
                        }

                        if (cse_farmer.curr_dir == 'v') {
                            if (cse_farmer.curr_row < length) {
                                farm_land[row + 1][col].seed_name = 
                                seed_collection[i].name;
                                seed_collection[i].amount--;
                            } 
                        }

                        if (cse_farmer.curr_dir == '>') {    
                            if (cse_farmer.curr_col < length) {
                                farm_land[row][col + 1].seed_name = 
                                seed_collection[i].name;
                                seed_collection[i].amount--;
                            }
                        }

                        if (cse_farmer.curr_dir == '<') {
                            if (cse_farmer.curr_col > boundary) {
                                farm_land[row][col - 1].seed_name = 
                                seed_collection[i].name;
                                seed_collection[i].amount--;
                            }
                        }
                    }
                    i++;
                }
            }
            printf("Enter command: ");
        }
        //enter the command 'p' that scattering the seed on the land
        if (command == 'p') {
            int row = cse_farmer.curr_row;
            int col = cse_farmer.curr_col;
            int length = 7;
            int loop = 0;
            //"loop" is to check for the user's input problems

            char seed_scatter;
            scanf(" %c", &seed_scatter);

            int i = 0;
            //let the scanf letter be lowercase letter
            if (seed_scatter < 'a' || seed_scatter > 'z') {
                printf("  Seed name has to be a lowercase letter\n");
            }

            else {
                while (i < num) {
                    if (seed_scatter == seed_collection[i].name) {
                        loop = 1;
                        if (cse_farmer.curr_dir == '^' || cse_farmer.curr_dir == '<') {
                            printf("  You cannot scatter seeds ^ or <\n");
                            loop = 1;
                        }
                        if (cse_farmer.curr_dir == '>') {
                            if (col > length) {}
                            //if statement said that if "cse_farmer.curr_col" bigger than
                            //and equal to seven which is far away 
                            //from the game area, then the program stop
                            else {
                                while (seed_collection[i].amount != 0 && col <= length) {
                                    farm_land[row][col++].seed_name = 
                                    seed_collection[i].name;
                                    seed_collection[i].amount--;
                                }
                            }                           
                        }

                        if (cse_farmer.curr_dir == 'v') {
                            if (row > length) {} 
                            //do not need to run for this restriction
                            //the same way for "cse_farmer.curr_row" that I mentioned
                            else {
                                while (seed_collection[i].amount != 0 && row <= length) {
                                    farm_land[row++][col].seed_name = 
                                    seed_collection[i].name;
                                    seed_collection[i].amount--;
                                }
                            }
                        }
                    }
                    i++;
                }
                if (loop == 0) {
                    printf("  There is no seed with the name '%c'\n", seed_scatter);
                }
            }
            printf("Enter command: ");
        }
        //enter the command 'w' that Square Watering on the land
        if (command == 'w') {
            int row = cse_farmer.curr_row;
            int col = cse_farmer.curr_col;
            int size = 0;
            int boundary = 0;
            int length = 7;
            scanf(" %d", &size);
            //No negative integers allows user to type
            if (size <= 0) {
                printf("  The size argument needs to be a non-negative integer\n");
            }
            if (size >= boundary) {
                int down = row - size;
                int left = col - size;
                int up_line = row + size;
                int right = col + size;
                //set up the boundary and length to prevent
                //the farmer from crossing the border  
                if (left < boundary) {
                    left = 0;
                }
                if (down < boundary) {
                    down = 0;
                }
                if (right > length) {
                    right = length;
                }
                if (up_line > length) {
                    up_line = length;
                }
                //Water the land
                int start = down;
                while (start <= up_line) {
                    int j = left;
                    while (j <= right) {
                        farm_land[start][j].is_watered = TRUE;
                        j++;
                    }
                    start++;
                }
            }
            printf("Enter command: ");
        }
        //enter the command 'n' that advancing to the next day
        if (command == 'n') {
            daytime++;
            int length = 8;

            //go to next day
            printf("  Advancing to the next day... Day %d, let's go!\n", daytime);

            //intialise the farmer           
            cse_farmer.curr_col = 0;
            cse_farmer.curr_row = 0;
            cse_farmer.curr_dir = '>';

            //The growed seeds will die
            for(int start = 0; start < length; start++) {
                for(int end = 0; end < length; end++) {
                    if (farm_land[start][end].seed_name <= 'Z' && 
                    farm_land[start][end].seed_name >= 'A') {
                        farm_land[start][end].is_watered = FALSE;
                        farm_land[start][end].seed_name = NO_SEED;
                    }
                }
            }

            for(int start = 0; start < length; start++) {
                for(int end = 0; end < length; end++) {
                    //grow
                    if ((farm_land[start][end].seed_name <= 'z' && 
                    farm_land[start][end].seed_name >= 'a') && 
                    farm_land[start][end].is_watered == TRUE) {
                        //it need to change the letter from ASSIC, 
                        //which is the technique I used in previous lab exercise
                        farm_land[start][end].seed_name = 
                        farm_land[start][end].seed_name - 32;
                        farm_land[start][end].is_watered = FALSE;
                    }
                    //die
                    else if ((farm_land[start][end].seed_name <= 'z' && 
                    farm_land[start][end].seed_name >= 'a') && 
                    farm_land[start][end].is_watered == FALSE) {
                        farm_land[start][end].seed_name = NO_SEED;
                    }
                }
            }

            //Become unwatered land
            for(int start = 0; start < length; start++) {
                for(int end = 0; end < length; end++) {
                    farm_land[start][end].is_watered = FALSE;
                }
            }
            printf("Enter command: ");
        }
        //enter the command 'h' that Harvesting Adjacent Land
        if (command == 'h') {
            int col = cse_farmer.curr_col;
            int row = cse_farmer.curr_col;
            int boundary = 0;
            int length = 8;

            if (cse_farmer.curr_dir == '^') {
                row--;
            }
            if (cse_farmer.curr_dir == 'v') {
                row++;
            }
            if (cse_farmer.curr_dir == '<') {
                col--;
            }
            if (cse_farmer.curr_dir == '>') {
                col++;
            }

            if (col < length && col >= boundary 
            && row < length && row >= boundary) {
                if (farm_land[row][col].seed_name <= 'Z' && 
                farm_land[row][col].seed_name >= 'A') {
                    //same technique from ascii I mentioned in previous step
                    printf("  Plant '%c' was harvested, resulting in 5 '%c' seed(s)\n", 
                    farm_land[row][col].seed_name, farm_land[row][col].seed_name + 32);
                    for (int i = 0; i < num; i++) {
                        if (seed_collection[i].name == 
                        farm_land[row][col].seed_name + 32) {
                            //"When harvesting a plant, you get 5 seeds of the same type."
                            //the hint from CSE VALLEY
                            seed_collection[i].amount = seed_collection[i].amount + 5;
                        }
                    }
                    farm_land[row][col].seed_name = NO_SEED;
                } 
            }
            printf("Enter command: ");
        }

        //enter the command 't' to trade seed
        if (command == 't') {
            char sell_seed;
            scanf(" %c", &sell_seed);
            int trade_num;
            scanf(" %d", &trade_num);
            char buy_seed;
            scanf(" %c", &buy_seed);
            int i = 0;
            int j = 0;
            int flag = TRUE;
            //"flag" is use to record for user's problematic input

            if ((sell_seed < 'a' || sell_seed > 'z'
            || buy_seed < 'a' || buy_seed > 'z') ) {
                printf("  Seed name has to be a lowercase letter\n");
                flag = FALSE;
            }
            
            for (i = 0; i < num; i++) {
                if (sell_seed == seed_collection[i].name) {
                    if (seed_collection[i].amount < trade_num && flag) {
                        printf("  You don't have enough seeds to be traded\n");
                        flag = FALSE;
                    }
                    break;
                }
            }

            if (i == num && flag) {
                printf("  You don't have the seeds to be traded\n");
                flag = FALSE;
            }


            if (trade_num < 0 && flag) {
                printf("  You can't trade negative seeds\n");
                flag = FALSE;
            }

            if (flag) {
                for (j = 0; j < num; j++) {
                    if (seed_collection[j].name == buy_seed) {
                        seed_collection[i].amount = seed_collection[i].amount - trade_num;
                        seed_collection[j].amount = seed_collection[j].amount + trade_num;
                        break;
                    }
                }
                if (j == num) {
                    seed_collection[num].name = buy_seed;
                    seed_collection[i].amount = seed_collection[i].amount - trade_num;
                    seed_collection[num].amount = seed_collection[num].amount + trade_num;
                    num++;
                }
            }
            printf("Enter command: ");
        }    
    }
    return 0;
}


////////////////////////////////
//     Provided Functions     //
////////////////////////////////

// Prints the structs land (including locating where the
// farmer is)
// You will need this function in Stage 2.
void print_land(struct land farm_land[LAND_SIZE][LAND_SIZE], struct farmer cse_farmer) {
    printf("|---|---|---|---|---|---|---|---|\n");
    int i = 0;
    while (i < LAND_SIZE) {
        print_top_row(farm_land, i);
        // only prints mid and bottom row when the farmer
        // is in that row
        if (i == cse_farmer.curr_row) {
            print_farmer_row(farm_land, cse_farmer);
        }
        printf("|---|---|---|---|---|---|---|---|\n");
        i++;
    }
}

// NOTE: You do not need to directly call any of the functions
// below this point. You are allowed to modify them, but you
// do not need to.

// Initialises struct farmer to its default state upon starting
// in which the farmer will be on the top left of the farm
// facing to the right (as noted by '>')
struct farmer initialise_farmer(struct farmer cse_farmer) {
    cse_farmer.curr_col = 0;
    cse_farmer.curr_row = 0;
    cse_farmer.curr_dir = '>';
    return cse_farmer;
}

// Initialises a 2d array of struct land to its default state 
// upon starting, which is that all land is unwatered and
// contains no seed
void initialise_land(struct land farm_land[LAND_SIZE][LAND_SIZE]) {
    int i = 0;
    while (i < LAND_SIZE) {
        int j = 0;
        while (j < LAND_SIZE) {
            farm_land[i][j].is_watered = FALSE;
            farm_land[i][j].seed_name = NO_SEED;
            j++;
        }
        i++;
    }
}

// Initialises struct farmer to its default state upon starting,
// which that all names are initialised as NO_SEED and its
// amount is 0
void initialise_seeds(struct seeds seed_collection[MAX_NUM_SEED_TYPES]) {
    int i = 0;
    while (i < MAX_NUM_SEED_TYPES) {
        seed_collection[i].amount = 0;
        seed_collection[i].name = NO_SEED;
        i++;
    }
}

////////////////////////////////
//      Helper Functions      //
////////////////////////////////

// prints the top row of a particular struct land
void print_top_row(struct land farm_land[LAND_SIZE][LAND_SIZE], int row) {
    int j = 0;
    while (j < LAND_SIZE) {
        printf("|");
        printf("%c", farm_land[row][j].seed_name);
        printf(" ");
        if (farm_land[row][j].is_watered == TRUE) {
            printf("W");
        } else {
            printf(" ");
        }
        j++;
    }
    printf("|");
    printf("\n");
}

// prints the 2 additional row when a farmer is in
// a particular row
void print_farmer_row(struct land farm_land[LAND_SIZE][LAND_SIZE], 
                      struct farmer cse_farmer)  {
    int j = 0;
    while (j < LAND_SIZE) {
        printf("|");
        if (j == cse_farmer.curr_col) {
            if (cse_farmer.curr_dir == '<') {
                printf("<");
            } else {
                printf(" ");
            }
            if (cse_farmer.curr_dir == '^') {
                printf("^");
            } else {
                printf("f");
            }
            if (cse_farmer.curr_dir == '>') {
                printf(">");
            } else {
                printf(" ");
            }
        } else {
            printf("   ");
        }
        j++;
    }
    printf("|");
    printf("\n");
    j = 0;
    while (j < LAND_SIZE) {
        printf("|");
        if (j == cse_farmer.curr_col) {
            printf(" ");
            if (cse_farmer.curr_dir == 'v') {
                printf("v");
            } else if (cse_farmer.curr_dir == '^') {
                printf("f");
            } else {
                printf(" ");
            }
            printf(" ");
        } else {
            printf("   ");
        }
        j++;
    }
    printf("|");
    printf("\n");
}
