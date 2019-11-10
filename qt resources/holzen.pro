QMAKE_CXX = /usr/bin/clang++-3.8

CONFIG += c++14

QT += core widgets

ALEPH = /home/josmar/Escritorio/Aleph-w

INCLUDEPATH += $${ALEPH}

LIBS += -L $${ALEPH} -lAleph -lgsl -lgslcblas -lm -lX11

               
HEADERS += \
bar.hh \
singleton.H \
entity.hh \
creature.hh \
object.hh \
noninteractuable.hh \
interactuable.hh \
consumable.hh \
armament.hh\
smallhealthpotion.hh \
bighealthpotion.hh \
smallmanapotion.hh \
bigmanapotion.hh \
bush.hh \
tree.hh \
chest.hh \
inventory.hh \
inventorybox.hh \
arrow.hh \
parser.hh \
hero.hh \
block.hh \
state.hh \
bee.hh \
chase.hh \
attack.hh \
alert.hh \
scenario.hh \
menu.hh \

SOURCES += \
bar.cc \
entity.cc \
creature.cc \
object.cc \
noninteractuable.cc \
interactuable.cc \
consumable.cc \
armament.cc\
smallhealthpotion.cc \
bighealthpotion.cc \
smallmanapotion.cc \
bigmanapotion.cc \
bush.cc \
tree.cc \
chest.cc \
inventory.cc \
inventorybox.cc \
arrow.cc \
parser.cc \
hero.cc \
block.cc \
bee.cc \
chase.cc \
attack.cc \
alert.cc \
scenario.cc \
menu.cc \
main.cc \

RESOURCES += \
    sprites.qrc
