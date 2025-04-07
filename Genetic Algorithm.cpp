
void run_genetic_algorithm(vector<Chromosome>& population) {
    for (int generation = 0; generation < MAX_GENERATIONS; generation++) {
        sort(population.begin(), population.end(), compare_by_fitness);

        cout << "Generation " << generation
             << " | Best fitness: " << population[0].fitness << endl;

        vector<Chromosome> new_population;

        // Elitism: keep top 2
        new_population.push_back(population[0]);
        new_population.push_back(population[1]);

        // Create new population
        while (new_population.size() < POP_SIZE) {
            int i = rand() % (POP_SIZE / 2);
            int j = rand() % (POP_SIZE / 2);
            auto [child1, child2] = crossover(population[i], population[j]);

            child1.mutate();
            child2.mutate();

            new_population.push_back(child1);
            if (new_population.size() < POP_SIZE)
                new_population.push_back(child2);
        }

        population = new_population;
    }
}