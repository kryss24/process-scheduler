void PriorityScheduling() {
    // Trier les processus par temps d'arrivée
    std::sort(processes.begin(), processes.end(),
              [](const Process& a, const Process& b) {
                  return a.arrivalTime < b.arrivalTime;
              });

    int currentTime = 0;
    std::vector<Process*> readyQueue;

    while (!processes.empty() || !readyQueue.empty()) {
        // Ajouter les processus qui sont arrivés au temps actuel dans la file d'attente
        for (auto it = processes.begin(); it != processes.end();) {
            if (it->arrivalTime <= currentTime) {
                readyQueue.push_back(&(*it));
                it = processes.erase(it); // Supprime le processus de la liste
            } else {
                ++it;
            }
        }

        // Si la file d'attente est vide, avancer le temps
        if (readyQueue.empty()) {
            currentTime++;
            continue;
        }

        // Trouver le processus avec la plus grande priorité dans la file d'attente
        auto highestPriority = std::max_element(readyQueue.begin(), readyQueue.end(),
            [](const Process* a, const Process* b) {
                if (a->priority == b->priority) {
                    return a->arrivalTime < b->arrivalTime; // FCFS si même priorité
                }
                return a->priority < b->priority; // Priorité (plus grande valeur)
            });

        Process* currentProcess = *highestPriority;
        readyQueue.erase(highestPriority);

        // Enregistrer le temps de début et simuler l'exécution
        currentProcess->startTime = currentTime;
        currentTime += currentProcess->remainingTime; // Avancer le temps de l'unité restante
        currentProcess->remainingTime = 0; // Le processus est terminé

        // Calculer le temps d'attente et le temps de rotation
        currentProcess->turnaroundTime = currentTime - currentProcess->arrivalTime;
        currentProcess->waitingTime = currentProcess->turnaroundTime - currentProcess->burstTime;

        // Afficher les résultats pour le processus
        std::cout << "Process ID: " << currentProcess->id
                  << ", Start Time: " << currentProcess->startTime
                  << ", Turnaround Time: " << currentProcess->turnaroundTime
                  << ", Waiting Time: " << currentProcess->waitingTime << std::endl;
    }
}