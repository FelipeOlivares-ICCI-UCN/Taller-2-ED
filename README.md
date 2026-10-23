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

## Choice Tree
First Value: Yes
Second Value: No

- Pain is Greater than 6 (Emergency)
    - Has Trauma? (Accident or Heart attack)
        - Has neurological symptoms (Was hit on the head);
            - Neurology (Self explanatory)
            - Traumatology (Another accident)
        - Has pain in the chest? (KindOfPain == "Pecho")
            - Cardiology (Heart Attack)
            - Urgency (Another unexplained pain)
    - Estimed Stay is more than 2? (somewhat long stay)
        - Age is less than 14
            - Pediatry (Child recovery)
            - Hospitalization (Adults)
        - Need Surgery?
            - Surgery (Self Explanatory)
            - General Medicine (Short doctor visit) (Default case)
Due to the default values in class Paciente, we are allowed to not worry about not having enough info.
