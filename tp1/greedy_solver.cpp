#include "greedy_solver.h"


GreedySolver::GreedySolver() {}

GreedySolver::GreedySolver(TaxiAssignmentInstance &instance) {
    this->_instance = instance;
    this->_objective_value = 0;
    this->_solution_status = 0;
    this->_solution_time = 0;
}

void GreedySolver::setInstance(TaxiAssignmentInstance &instance) {
    this->_instance = instance;
}

void GreedySolver::solve() {
    auto start = std::chrono::high_resolution_clock::now();
    auto matriz = _instance.dist;
    int n = _instance.n;
    //auto solucion = TaxiAssignmentSolution(n);
    for (int j = 0; j < n; j++){
        int min = 99999;
        int fila;
        for (int i = 0; i < n ; i++){
            if ((matriz[i][j] < min) && (_solution.isTaxiAssigned(i) == false)){
                min = matriz[i][j];
                fila = i;
            }
        }
        _solution.assign(fila,j);

        // falta tiempo de resolucion
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto tiempo_transcurrido = end - start;
    // _solution_time = tiempo_transcurrido;

}

double GreedySolver::getObjectiveValue() const {
    return this->_objective_value;
}

TaxiAssignmentSolution GreedySolver::getSolution() const {
    return this->_solution;
}

int GreedySolver::getSolutionStatus() const {
    return this->_solution_status;
}

double GreedySolver::getSolutionTime() const {
    return this->_solution_time;
}


