// Person 2 - Chromosome Structure
struct Chromosome {
    vector<int> genes;
    int fitness = 0;

    Chromosome() {
        genes.resize(CHROMO_LENGTH);
        for (int i = 0; i < CHROMO_LENGTH; i++)
            genes[i] = rand() % 2;
        calculate_fitness();
    }

    void calculate_fitness() {
        fitness = count(genes.begin(), genes.end(), 1);
    }

    void mutate() {
        for (int i = 0; i < CHROMO_LENGTH; i++) {
            if ((double)rand() / RAND_MAX < MUTATION_RATE)
                genes[i] = 1 - genes[i];
        }
        calculate_fitness();
    }
};