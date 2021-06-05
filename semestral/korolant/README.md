# Kalendář
# Autor: Anton Korolov

``` 
English version 
```
## About aplication

The "Calendar" application, the user launches the application and can use simple commands to the console to control the application.
Commands:
- `new ...` creates a new event, the application asks for more parameters
- `delete ...` deletes an event, the application asks for other parameters
- `listEvents` lists all events that are on the calendar
- `repeat ...` sets the event selected by the user, repeatedly, the application asks for other parameters
- `move ...` moves the event selected by the user, the application asks for other parameters
- `findFristPossible ...` finds the closest possible date for moving the event selected by the user, the application asks for other parameters
- `showDaily` daily view of the calendar with the event it has
- `showWeekly` a weekly view of the calendar with the event it has
- `showMonthly` monthly calendar view with the event it has
- `showYearly` annual calendar display with the event it has
- `find ...` finds the event, the application asks for more parameters
- `load [filename]` loads events from a file
- `save [filename]` saves events to a file
- `edit ...` changes the event, the application asks for other parameters
- `help` displays help
- `quit` terminates the program

The user creates either a required or optional event.

The difference will only be in the statement. It's just for the user to know if they have to attend this event.

Events can be loaded from a file (it should have the exact shape). If the file cannot be opened, the application throws an exception.

It is also possible to upload (export) all events that are in the calendar to the file.

------------------------------------------------------------------------------------------------------------------------

## Showing:
```

# Calendar by years:
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

# Calendar by months:
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

# Calendar by weeks:

--------------June---------------
  Sun  Mon  Tue  Wed  Thu  Fri  Sat
              1    2    3    4    5

# Calendar by days:

Events for a 13/07/2021:
[ID:6][Optional][01/01/2000 00:00 - 01/01/2100 00:00] Name: First 100 years in 2000th
	Place: All world
	Description: First 100 years in 2000th in our common world, that is so small and big and so beautiful!

```

------------------------------------------------------------------------------------------------------------------------
## Description of the polymorphism and reflection on how to facilitate the work

I use polymorphism in "CView" and "CEvent" classes

In the "CView" class, polymorphism makes my listing easier.
Thanks to the polymorphism, the calendar can be displayed differently, the display could be daily, weekly and monthly and yearly.

In the "CView" class, the polymorphism also makes navigation easier for me.
It can be navigated forwards and backwards, depending on how the user would like it.

In the "CEvent" class, thanks to the polymorphism, I divide the Event into mandatory and optional.




``` 
Czech version 
```

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
Dá se díky polymorfismu zobrazit kalendář jinak, zobrazení by mohlo být denní, tydenní a měsiční a roční.

Ve třídě "CView" polymorfismus mi také usnadňuje navigaci.
Dá se díky navigovat vpřed a vzad, zaleží na to, jak by to chtěl uživatel.

Ve třídě "CEvent" díky polymorfismu rozděluji událost(Event) na povinnou(required) a nepovinnou(optional).

------------------------------------------------------------------------------------------------------------------------