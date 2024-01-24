***Let there be light !***

# Introduction

Durant ce projet on va faire de la conception conjointe impliquant un FPGA et un processeur Soft Nios2. À travers cette démarche, nous aborderons la création d'un système minimal où on va pouvoir changer la vitesse d'un chenillard à l'aide de 4 switchs, et le lancer avec un bouton poussoir. Nous instancierons les Switchs (SW) de la carte en tant que périphériques au Nios2. Quatre d'entre eux seront réservés à la gestion de la vitesse du chenillard, avec 4 niveaux de vitesses différents, programmés en code C. 

# Présentation de l'architecture :


![Capture d'écran 2024-01-24 105459](https://github.com/ESN2024/BOUTARF_lab1/assets/121360725/328545ab-365d-47c6-84d2-e55ccd445030)



L'architecture repose sur un ensemble de composants. On a, de prime abord, un processeur Soft Nios 2, nous avons ensuite une mémoire On-Chip qui permet un accès rapide aux données. L'intégration d'un JTAG UART facilite la communication et le debugage du système. On a de plus deux PIOs (Parallel Input/Output) pour l'interaction avec l'environnement extérieur. Le premier, configuré en output, et est dédié à la commande des LED, tandis que le second, en mode input, est spécifiquement conçu pour interagir avec les boutons poussoirs et les switchs. Cette configuration permet la mise en œuvre d'un système complet capable de réaliser le chenillard, en offrant la possibilité d'ajuster la vitesse du chenillard à l'aide des boutons et des switchs. 

# Cablage du système :
La figure ci-dessous présente le cablage du système sur QSYS, détaillant la connexion entre les différents composants. 


![image](https://github.com/ESN2024/BOUTARF_lab1/assets/121360725/d804ef3a-c20a-4880-a2ef-b262c20641d6)

# Résultats :

On peut voir, sur la vidéo ci-dessous, un chenillard qui change de vitesse à chaque fois qu'on change un switch. Le bouton poussoir a servi de lancer ke chenillard.

https://github.com/ESN2024/BOUTARF_lab1/assets/121360725/b7ebfcce-9dc2-472b-beee-92484f70a4bf


# Conclusion

