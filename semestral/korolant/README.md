# Kalendář
# Autor: Anton Korolov

## O aplikaci
Aplikace "Kalendář", uživatel aplikaci spustí a může pomocí jednoduchých příkazů do konzole ovládát aplikaci.
Příkazy:
- `new ...` vytvoří novou událost, aplikace se dotáže na další parametry
- `delete ...` smaže nějakou událost, aplikace se dotáže na další parametry
- `listEvents` výpíše vsechny události, které jsou v kalendáři
- `repeat ...` nastaví událost, kterou vybere uživatel, opakovaně, aplikace se dotáže na další parametry
- `move ...` přesune událost, kterou vybere uživatel, aplikace se dotáže na další parametry
- `findFristPossible ...` vyhledá nejbližší možný termín přesunu události, kterou vybere uživatel, aplikace se dotáže na další parametry
- `showDaily` denní zobrazení kalendáře s udalostí, které má
- `showWeekly` tydenní zobrazení kalendáře s udalostí, které má
- `showMonthly` měsíční zobrazení kalendáře s udalostí, které má
- `showYearly` roční zobrazení kalendáře s udalostí, které má
- `find ...` vyhledá událost,  aplikace se dotáže na další parametry
- `load [filename]` načte události ze souboru
- `save [filename]` uloží události do souboru
- `edit ...` změní událost, aplikace se dotáže na další parametry
- `help` zobrazí nápovědu
- `quit` ukončí program

Uživatel vytvoří buď povinnou(required) nebo volitelnou(optional) událost.

Rozdíl bude jenom v výpisu. Je to jen pro uživatele, aby věděl, musí-li této událostí zúčastnit.

Událostí lze načíst ze souboru(měl by mít přesný tvar). Když soubor nepůjde otevřít, aplikace výhodí výjimku.

Stejně tak lze do souboru nahrat(exportovat) všechny událostí, které jsou v kalendáří.


## Výpis:
```

# Roční zobrazení kalendáře př.:
          Calendar - "year"
  ------------November-------------
  Sun  Mon  Tue  Wed  Thu  Fri  Sat
         1    2    3    4    5    6
    7    8    9   10   11   12   13
   14   15   16   17   18   19   20
   21   22   23   24   25   26   27
   28   29   30

[ID:6][Optional][01/01/2000 00:00 - 01/01/2100 00:00] Name: First 100 years in 2000th
	Place: All world
	Description: First 100 years in 2000th in our common world, that is so small and big and so beautiful!


  ------------December-------------
  Sun  Mon  Tue  Wed  Thu  Fri  Sat
                   1    2    3    4
    5    6    7    8    9   10   11
   12   13   14   15   16   17   18
   19   20   21   22   23   24   25
   26   27   28   29   30   31

# Měsiční zobrazení kalendáře př.:
          Calendar - 2021

  --------------July---------------
  Sun  Mon  Tue  Wed  Thu  Fri  Sat
                             1    2
    3    4    5    6    7    8    9
   10   11   12   13   14   15   16
   17   18   19   20   21   22   23
   24   25   26   27   28   29   30
   31

[ID:6][Optional][01/01/2000 00:00 - 01/01/2100 00:00] Name: First 100 years in 2000th
	Place: All world
	Description: First 100 years in 2000th in our common world, that is so small and big and so beautiful!

# Tydenní zobrazení kalendáře př.:

--------------June---------------
  Sun  Mon  Tue  Wed  Thu  Fri  Sat
              1    2    3    4    5

# Denní zobrazení kalendáře př.:

Events for a 13/07/2021:
[ID:6][Optional][01/01/2000 00:00 - 01/01/2100 00:00] Name: First 100 years in 2000th
	Place: All world
	Description: First 100 years in 2000th in our common world, that is so small and big and so beautiful!

```
------------------------------------------------------------------------------------------------------------------------
## Popis polymorfismu a zamyšlení v čem usnadní práci
Polymorfismus používám ve třídách "CView" a "CEvent"

Ve třídě "CView" polymorfismus mi usnadní výpis.
Dá se díky polymorfismu zobrazit kalendář jinak, zobrazení by mohlo být denní, tydenní a měsiční.

Ve třídě "CEvent" díky polymorfismu rozděluji událost(Event) na povinnou(required) a nepovinnou(optional).

------------------------------------------------------------------------------------------------------------------------