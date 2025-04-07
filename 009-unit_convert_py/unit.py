def convert_mass(value, current, target):
    """
    Converts the mass unit from one to another
    
    """
    conversion_rates_to_kg = {
        "Kilogram": 1.0,
        "Pound": 0.453592,
        "Stone": 6.35029,
        "Jin": 0.5,
        "Seer": 1.25,
        "Gram": 0.001,
        "Oka": 1.2829
    }
    # Change the unit to Kilogram.
    value_in_kg = value * conversion_rates_to_kg[current]
    # Converting Kilogram to target unit.
    converted_value = value_in_kg / conversion_rates_to_kg[target]
    
    return converted_value
