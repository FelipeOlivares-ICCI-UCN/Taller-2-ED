Made by Felipe Olivares ICCI 21656773-0

## Data Format
ID;Name;Age;BodyHeat;BloodPressure;Pain;KindOfPain;Trauma;NeurologicalSimtoms;RequiresSurgery;EstimedStay

- ID: int, must be unique
- Name: string
- Age: int
- Body heat: float
- BloodPressure: two integers separated by a '/' symbol.
    - Sistionic blood pressure: first integer
    - Diastolic blood pressure: second integer
- Pain: int, must be between 0 and 10
- KindOfPain: string, possible values are: "Cabeza", "Pecho", "Abdomen", "Extremidad", "Otro"
- Trauma: int, 0 if it exist and 1 if not.
- NeurologicalSimtoms: int, 0 if is arent present and 1 if they are
- RequiresSurgery: int, 0 if itsnt needed and 1 if it is.
- Estimed Stay, int, measured in days.

