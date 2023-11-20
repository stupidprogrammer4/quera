t = int(input())
all_test = [[input().split(), input().split()] for _ in range(t)]
days_dict = ["shanbe", "1shanbe", "2shanbe", "3shanbe", "4shanbe","5shanbe", "jome"] # NOQA
months_dict = ["Farvardin", "Ordibehesht", "Khordad", "Tir", "Mordad", "Shahrivar", "Mehr", "Aban", "Azar", "Dey", "Bahman", "Esfand"] # NOQA

def calculate_days(today: list, desired_day: list) -> str: # NOQA
    days_until_desired_day = 0
    today[0] = int(today[0])
    desired_day[0] = int(desired_day[0])
    if today[0] == desired_day[0] and today[1] == desired_day[1]:
        return today[2]
    elif today[1] == desired_day[1]:
        if today[0] < desired_day[0]:
            d = desired_day[0] - today[0] % 7
            if d == 0:
                return today[2]
            else:
                return days_dict[(days_dict.index(today[2]) + d) % 7]
        elif today[0] > desired_day[0]:
            d = abs(today[0] - desired_day[0])
            if d == 0:
                return desired_day[2]
            else:
                return days_dict[(days_dict.index(today[2]) - d) % 7]
        else:
            print(today[2])

    else:
        todays_month = months_dict.index(today[1]) + 1
        desired_days_month = months_dict.index(desired_day[1]) + 1
        days_until_desired_day = 0
        if todays_month < desired_days_month:
            if todays_month <= 6:
                days_until_desired_day += 31 - today[0]
            elif 6 < todays_month < 12:
                days_until_desired_day += 30 - today[0]
            elif todays_month == 12:
                days_until_desired_day += 29 - today[0]

            days_until_desired_day += desired_day[0]

            i = todays_month + 1
            while i < desired_days_month:
                if i <= 6:
                    days_until_desired_day += 31
                    i += 1
                elif 6 < i < 12:
                    days_until_desired_day += 30
                    i += 1
                elif i == 12:
                    days_until_desired_day += 29
                    i += 1

            d = days_until_desired_day % 7
            if d == 0:
                return today[2]
            else:
                return days_dict[(days_dict.index(today[2]) + d) % 7]

        else:
            td = desired_day
            ds = today
            tdm = desired_days_month
            dsm = todays_month

            if tdm <= 6:
                days_until_desired_day += 31 - td[0]
            elif 6 < tdm < 12:
                days_until_desired_day += 30 - td[0]
            else:
                days_until_desired_day += 29 - td[0]
            days_until_desired_day += ds[0]

            i = tdm + 1
            while i < dsm:
                if i <= 6:
                    days_until_desired_day += 31
                    i += 1
                elif 6 < i < 12:
                    days_until_desired_day += 30
                    i += 1
                else:
                    days_until_desired_day += 29
                    i += 1

            d = days_until_desired_day % 7
            if d == 0:
                return ds[2]
            else:
                return days_dict[(days_dict.index(today[2]) - d) % 7]


for test in all_test:
    today1, desired_day1 = test
    print(calculate_days(today1, desired_day1))