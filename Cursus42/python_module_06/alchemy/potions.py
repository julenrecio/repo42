from . import elements as ae
from .. import elements as e # invalid import

def strength_potion():
    return "Strength potion brewed with '" + e.create_fire() + "' and '" + e.create_water() + "'"

def healing_potion():
    return "Healing potion brewed with '" + ae.create_earth() + "' and '" + ae.create_air() + "'"