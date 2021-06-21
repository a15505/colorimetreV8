Le colorimètreV8 possède les composants suivants:
- 1 Module Capteur analogique BPW77NB relié à A0
- 1 Module LED reliée à D3 (la couleur dépend de la longueur d'onde à absorber)
- 1 Module Arduino avec blindage V5
- 1 Écran LCD1602 I2C

Pièces à imprimer 3D
https://grabcad.com/library/colorimetre-arduino-v8-1

Fonctionnement

Le module arduino ajuste le niveau d'intensité lumineuse, mesure le signal du capteur et l'écan ALC affiche la concentration.
Le module détecteur capte une partie de la lumière émise par le module DEL car la solution absorbe la lumière.
Les signaux du capteur et de la sonde sont filtrés par des condensateur afin d'éliminer les variations PWM.

Résumé du code
setup() 
Ajuste automatiquement le niveau d'intensité lumineuse de la DEL au démarrage afin d'obtenir une valeur de référence choisie (blanc).
loop() 
Mesure la valeur A0 du détecteur et affiche celle-ci à l'écran ACL.

Prototype fonctionnel
https://youtu.be/kDdkpL_VeAQ

Créé par Yvon Quémener
19 juin 2021
