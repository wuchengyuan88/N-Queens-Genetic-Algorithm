#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <typeinfo>
#include <cmath>
#include <set>
using namespace std;



// Initialize board 
// Returns a random vector that represents row (i coordinate) of the queens
vector<int> initialize(const int &N){
    vector<int> board;
    for (int i=0; i<N; i++){
        board.push_back(rand() % N);
    }
    return board;
} // End initialize()

void print_vec(const vector<int> &board){
    int N = board.size();

    // Print board vector
    cout << "[";
    for (int k=0; k<N; k++){
        cout << board[k] << " ";
    }
    cout << "]" << endl;
} // End print_vec()

// Print board
void print_board(const vector<int> &board){
    int N = board.size();

    // Print board vector
    print_vec(board);

    // Print 2D board
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (board[j]==i){
                cout << 'Q' << " ";
            }
            else{
                cout << '.' << " ";
            }
        }
        cout << endl;
    }
} // End print_board()

// Fitness function (no. of pairs of non-attacking queens)
int fitness(const vector<int> &board){
    int N = board.size();
    int fitness = 0;
    for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++){
            int queen1 = board[i];
            int queen2 = board[j];
            bool attack;
            // check same row
            if (queen1==queen2){
                attack = true;
            }
            // check diagonal
            else if (abs(queen1-queen2)==abs(i-j)){
                attack = true;
            }
            //by construction, guaranteed to be different column
            else{
                attack = false;
            }

            if (attack==false){
                fitness++;
            }
        }
    }
    return fitness;
} //end fitness()

vector<vector<int> > selection(const vector<vector<int> >&population, const vector<int> &fitness_vector, 
const int &sel_size, const float &weak_prob){
    vector<vector<int> > selected_pop;
    vector< pair <int,vector<int> > > sort_vect;

    int len = population.size();
    //cout << "len = " << len << endl;
    for (int i=0; i<len; i++){
        sort_vect.push_back(make_pair(fitness_vector[i], population[i]));
    }
    sort(sort_vect.begin(), sort_vect.end());

    // Remove duplicates 
    sort_vect.erase( unique( sort_vect.begin(), sort_vect.end() ), sort_vect.end() );
    int sort_len = sort_vect.size();
    //cout << "sort_len" << sort_len << endl;

    for (int i=1; i<=sel_size; i++){
        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        if (r<weak_prob){
            // randomly select a weak offspring
            vector<int> weak_board = sort_vect[rand() % sort_len].second;
            selected_pop.push_back(weak_board);
            //cout << "Weak offspring selected" << endl;
            //cout << "Fitness:" << fitness(weak_board) << endl;
        }
        else{
            vector<int> strong_board = sort_vect[sort_len-i].second;
            selected_pop.push_back(strong_board);
            //cout << "Strong offspring selected" << endl;
            //cout << "Fitness:" << fitness(strong_board) << endl;
        }
    } 
    //cout << "selected_pop.size()" << selected_pop.size() << endl;
    return selected_pop;
} // end selection

vector<vector<int> > cross_over(const vector<vector<int> >&population, const int &pop_size){
    vector<vector<int> > cross_pop = population;
    // initial population size
    int init_size = population.size();
    int N = population[0].size();

    while (cross_pop.size()<pop_size){
        // random pair for cross over
        vector<int> pair1 = population[rand() % init_size];
        vector<int> pair2 = population[rand() % init_size];
        //print_vec(pair1);
        //print_vec(pair2);
        // crossover location
        int cross_loc = rand() % (N-1);
        //cout << "cross_loc:" << cross_loc << endl;
        vector<int> A = vector<int>(pair1.begin(), pair1.begin()+cross_loc+1);
        vector<int> B = vector<int>(pair2.begin()+cross_loc+1, pair2.end());
        vector<int> AB;
        AB.reserve(N); // preallocate memory
        AB.insert( AB.end(), A.begin(), A.end() );
        AB.insert( AB.end(), B.begin(), B.end() );
        //print_vec(AB);
        cross_pop.push_back(AB);
    }

    return cross_pop;
} //end cross_over()

vector<vector<int> > mutate(const vector<vector<int> >&population, const float &prob){
    vector<vector<int> > mutate_pop = population;
    // initial population size
    int pop_size = population.size();
    int N = population[0].size();

    for (int i=0; i<pop_size; i++){
        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        if (r<prob){
            //cout << "Mutation" << endl;
            //print_vec(mutate_pop[i]);
            // Swap 2 indices randomly
            int rand1 = rand() % N;
            int rand2 = rand() % N;
            //cout << "rand1: " << rand1 << endl;
            //cout << "rand2: " << rand2 << endl;
            int temp = mutate_pop[i][rand1];
            mutate_pop[i][rand1] = mutate_pop[i][rand2];
            mutate_pop[i][rand2] = temp;
            //print_vec(mutate_pop[i]);
        }
    }
    return mutate_pop;
} //end mutate

int main(){
    // measure CPU time
    clock_t begin = clock();
    // Seed random generator
    srand(time(0));
    
    //////// Parameters ////////
    // Set dimension of board NxN
    int N=20;
    cout << "N = " << N << endl;
    // Fixed population size
    int pop_size = N*1000;
    // Selection size
    int sel_size = pop_size/10;
    // Probability of randomly including weak offspring in selection
    float weak_prob = 0.3;
    // Mutation probability
    float prob = 0.3;
    // Maximum generations to iterate
    int gen_max = 1000;
    ////////////////////////////

    // Maximum theoretical value of fitness (N choose 2)
    int f_max = (N*(N-1))/2;
    cout << "f_max=" << f_max << endl;
    // Current best fitness
    int f_curr = 0;
    // Population
    vector<vector<int> > population;
    // Fitness vector
    vector<int> fitness_vector;
    // Generation number
    int gen = 1;
    
    // Initialize Population
    for (int i=0; i<pop_size; i++){
        vector<int> board = initialize(N);
        population.push_back(board);
        //print_board(board);
        //cout << fitness(board) << endl;
        int f_score = fitness(board);
        fitness_vector.push_back(f_score);
        if (f_score>f_curr){
            f_curr = f_score;
        }
        if (f_score == f_max){
            cout << "Solution found:" << endl;
            print_board(board);
            break;
        }
    } //end for
    cout << "Generation " << gen << ": f_curr=" << f_curr << endl;
    gen++;
    
    while (f_curr<f_max && gen<gen_max){
        // Selection
        population = selection(population, fitness_vector, sel_size, weak_prob);
        //cout << population.size() << endl;
        
        /*
        cout << "index 0 board:" << endl;
        print_board(population[0]);
        cout << fitness(population[0]) << endl;
        cout << "index last board:" << endl;
        print_board(population[population.size()-1]);
        cout << fitness(population[population.size()-1]) << endl;
        */

        // Cross Over
        population = cross_over(population, pop_size);
        //cout << population.size() << endl; 

        // Mutation
        population = mutate(population,prob);

        // Calculate Fitness
        fitness_vector.clear();
        for (int i=0; i<pop_size; i++){
            vector<int> board = population[i];
            int f_score = fitness(board);
            fitness_vector.push_back(f_score);
            if (f_score>f_curr){
                f_curr = f_score;
                //print_board(board);
        }
        if (f_score == f_max){
            cout << "Solution found:" << endl;
            print_board(board);
            break;
        }
    }

        // Increment generation
        cout << "Generation " << gen << ": f_curr=" << f_curr << endl;
        gen++;
    } //end while

    //Time elapsed
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Time elapsed (seconds): " << elapsed_secs;
    return 0;
} // end main()