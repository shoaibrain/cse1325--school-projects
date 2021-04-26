#include "puzzle.h"
#include "solver.h"

#include <iostream>
#include <fstream>
#include <vector>

#include <algorithm>  // std::sort
#include <thread>
#include <mutex>

std::mutex m;
void helper(std::vector<Solution> &S_vector,std::string word, Puzzle puzzle){
	
	Solver solver{puzzle};
	
	Solution s = solver.solve(word);
	m.lock();
	S_vector.push_back(s);
	m.unlock();
}

int main(int argc, char* argv[]) {

   //int numPuzzle = 
    // Load the puzzles
    std::vector<Puzzle> puzzles;
    for(int i=1; i<argc; ++i) {
        try {
            std::string filename = std::string{argv[i]};
            std::ifstream ifs{filename};
            puzzles.push_back(Puzzle{filename, ifs});
        } catch(std::exception& e) {
            std::cerr << "Unable to open " << argv[i] << ": " 
                      << e.what() << std::endl;
        }
    }

    // Exit if one or more puzzles failed to load
    if((argc-1) != puzzles.size()) exit(-1);     
    
    // ----- All data loaded -----
    
    // Capture the solutions in a vector 
    std::vector<Solution> solutions;

     int nthreads = 4;
	 int for_each_thread = puzzles.size()/nthreads;

    // Loop through all of the loaded puzzles
    for(Puzzle& puzzle : puzzles) {
         
        // Find each word in the current puzzle
        for(std::string word : puzzle) {
        
            // Instance a Solver, and use it to solve for the word
            Solver solver{puzzle};
            //Solution s= solver.solve(word);
			
			//std::thread t{&Solver::solve, &solver, word};
			//solutions.push_back(s);
			
			//std::thread t1{helper,&solutions,word,puzzle};
			std::thread t{[&]{solver.solve(word);}};
			t.join();
			
			
			
        }
    }
	
    
    std::sort(solutions.begin(), solutions.end());
    for(Solution& s : solutions) std::cout << s << std::endl;
}
    
    
