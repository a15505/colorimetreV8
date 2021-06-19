Le colorimètreV8 possède les composants suivants:
- 1 Capteur analogique BPW77NB relié à A0
- 1 LED reliée à D3 (la couleur dépend de la longueur d'onde à absorber)
- 1 Écran LCD1602 I2C
- 2 condensateurs 10uF 16V
- 2 modules KY-018 modifiés (pcb utilisé seulement)

Pièces à imprimer 3D
https://grabcad.com/library/colorimetre-arduino-v8-1

Fonctionnement.

Le signal du capteur et de la sonde sont filtrés par un condensateur 10uF afin d'éliminer les variations PWM.
L'écan ALC affiche la concentration.

setup() 
Ajuste automatiquement le niveau d'intensité lumineuse de la DEL au démarrage afin d'obtenir une valeur de référence choisie (blanc).
loop() 
Mesure la valeur A0 du détecteur et affiche celle-ci à l'écran ACL.

Créé par Yvon Quémener
19 juin 2021
