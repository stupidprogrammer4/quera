import csv
fields = ['esm', 'famil', 'keshvar', 'rang', 'ashia', 'ghaza']
participants = {}
repeats = {x:{} for x in fields}
esm_famil_data = {x:[] for x in fields}
emtiaz_field = {x:10 for x in fields}

def ready_up():
    global esm_famil_data, fields
    with open('esm_famil_data.csv', encoding='utf8') as file:
        lst = list(csv.DictReader(file))
        for row in lst:
            for field in fields:
                if row[field].strip():
                    esm_famil_data[field].append(row[field].replace(' ', ''))
            

def add_participant(participant, answers):
    global participants, emtiaz_field
    participants[participant] = answers
    for field in answers:
        now = answers[field].replace(' ', '')
        if not now:
            emtiaz_field[field] = 15 
            continue
        if not repeats[field].get(now):
            repeats[field][now] = 1
        else: 
            repeats[field][now] += 1


def calculate_all():
    global participants, esm_famil_data, fields, emtiaz_field        
    output = {x: 0 for x in participants.keys()}
    for k, v in participants.items():
        for field in fields:
            now = v[field].replace(' ', '')
            if not now or not now in esm_famil_data[field]: 
                continue
            if repeats[field][now] > 1:
                output[k] += (emtiaz_field[field] - 5)
            elif repeats[field][now] == 1:
                output[k] += emtiaz_field[field]
            
    return output
