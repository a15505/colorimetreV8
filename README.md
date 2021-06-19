Le colorimètreV8 possède les composants suivants:
- 1 Capteur analogique BPW77NB relié à A0
- 1 LED reliée à D3 (la couleur dépend de la longueur d'onde à absorber)
- 1 Écran LCD1602 I2C
- 2 condensateurs 10uF 16V
- 2 modules KY-018 modifiés (pcb utilisé seulement)

Le signal du capteur et la sonde est filtré par un condensateur 10uF afin d'elliminer les variations PWM.
L'écan ALC affiche de la concentration.
Une fonction cal() ajuste automatiquement le niveau d'intensité lumineuse au démarrage afin d'obtenir une valeur de référence choisie (blanc).
Une fonction permet de transformer la valeur A0-1023 captée en valeur de concentration.

Créé par Yvon Quémener
19 juin 2021
