# MagicMicky's TADA68 layout

This is the basic TADA68 layout with a few changes:

* Swap left Win/cmd key with left alt key (Apple style)
* Redefine left column to have media keys / volume keys when using Fn
* Mouse pointer with Fn + arrow keys
* Enable backlight breathing
* Create an alias for locking the screens on mac OS with "Fn + `" (mapped to ctrl+shift+eject)


TODO:

* Find another use for CAPS key
* Map home/end somewhere (arrow keys?)
* Print screen?
* More backlight features?


## Layouts
```
Keymap _BL: Base Layer
,----------------------------------------------------------------.
|Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
|----------------------------------------------------------------|
|Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | << |
|----------------------------------------------------------------|
|CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return | >> |
|----------------------------------------------------------------|
|Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up| >| |
|----------------------------------------------------------------|
|Ctrl|Alt |CMD |        Space          |ALT |FN|Ctrl|Lef|Dow|Rig |
`----------------------------------------------------------------'

Keymap _FL: Function Layer
,----------------------------------------------------------------.
|   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |LCK |
|----------------------------------------------------------------|
|     |   |   |   |   |   |   |   |   |   |   |   |   |     | V- |
|----------------------------------------------------------------|
|      |   |   |   |   |   |   |   |   |   |   |   |        | V+ |
|----------------------------------------------------------------|
|        |   |   |Bl-|BL |BL+|BLB|   |   |   |   |      |   | Vm |
|----------------------------------------------------------------|
|    |    |    |                       |   |   |    |   |   |    |
`----------------------------------------------------------------'


```