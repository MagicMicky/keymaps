# MagicMicky's TADA68 layout

This is the basic TADA68 layout with a few changes:

* Swap left Win/cmd key with left alt key (Apple style)
* Redefine left column to have media keys / volume keys when using Fn
* Mouse pointer with Fn + arrow keys
* Create an alias for locking the screens on mac OS with "Fn + `" (mapped to ctrl+shift+eject)
* Rebind CAPS to FN
* Enable some specific shortcuts on right alt/Ctrl

## Ralt/Rctl
Instead alt/right ctrl, I tried to map some automator worflow, that will open/switch to specific application. The idea is to switch easily to my commonly used apps (Iterm, chrome, slack...).
I also wanted a Hide functionnality with a double tap on one of them, to easily, instantly hide Slack.

To enable those features, you need to create some specific automator workflow service and map to the shortcut detailed in keymap.c (KC_HSLK, KC_OTRM, KC_OCRM, KC_OCDE, KC_OSLK)

## Layouts
```
Keymap _BL: Base Layer
,----------------------------------------------------------------.
|Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
|----------------------------------------------------------------|
|Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | << |
|----------------------------------------------------------------|
|FN     |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return | >> |
|----------------------------------------------------------------|
|Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up| >| |
|----------------------------------------------------------------|
|Ctrl|Alt |CMD |        Space          | Slk|FN|Trm |Lef|Dow|Rig |
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
|    |    |    |                       | Crm|  |Cde |   |   |    |
`----------------------------------------------------------------'


```