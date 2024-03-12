movies, casts = {}, {}
movie_it, cast_it = 0, 0
deleted_casts, deleted_movies = set(), set()

class Movie:
    def __init__(self, title, date, quality):
        self.title = title 
        self.date = date
        self.quality = quality 
        self.casts = []

    def get_casts(self):
        global deleted_casts
        valid_casts = []
        for cast in self.casts:
            if cast not in deleted_casts:
                valid_casts.append(cast)
        valid_casts.sort()
        return valid_casts 

    def __str__(self):
        return "{" + f'title:"{self.title}", date:"{self.date}", quality:"{self.quality}", casts:{self.get_casts()}' + "}"


class Cast:
    def __init__(self, name):
        self.name = name 
        self.movies = []
    
    def get_movies(self):
        global deleted_movies 
        valid_movies = []
        for movie in self.movies:
            if movie not in deleted_movies:
                valid_movies.append(movie)
        valid_movies.sort()
        return valid_movies 

    def __str__(self):
        return "{" + f'name:"{self.name}", movies:{self.get_movies()}' + "}"


def is_valid_date(date: str) -> bool:
    if date.isdigit():
        if int(date) >= 1888 and int(date) <= 2024:
            return True 
    return False 

def add_movie(title, date, quality):
    global movies, movie_it 
    if len(title) > 20:
        return "invalid title"
    if not is_valid_date(date):
        return "invalid date"
    if quality not in ["720p", "1080p", "4K"]:
        return "invalid quality"
    movies[movie_it] = Movie(title, int(date), quality)
    movie_it += 1
    return f"added successfully {movie_it-1}"

def rem_movie(movie_id):
    global movies, deleted_movies 
    if not movies.get(movie_id):
        return "invalid movie id"
    del movies[movie_id]
    deleted_movies.add(movie_id)
    return f"removed successfully {movie_id}"

def add_cast(name):
    global casts, cast_it 
    if len(name) <= 20 and name.isalpha():
        casts[cast_it] = Cast(name)
        cast_it += 1
        return f"added successfully {cast_it-1}"

    return "invalid name"

def rem_cast(cast_id):
    global casts, deleted_casts 
    if not casts.get(cast_id):
        return "invalid cast id"
    del casts[cast_id]
    deleted_casts.add(cast_id)
    return f"removed successfully {cast_id}"
        

def show_movie(movie_id):
    global movies
    if not movies.get(movie_id):
        return "invalid movie id"
    return str(movies[movie_id])

def show_cast(cast_id):
    global casts
    if not casts.get(cast_id):
        return "invalid cast id"
    return str(casts[cast_id])


def link_cast_to_movie(cast_id, movie_id):
    global movies, casts 
    if not casts.get(cast_id):
        return "invalid cast id"
    if not movies.get(movie_id):
        return "invalid movie id"
    if movie_id in casts[cast_id].movies:
        return "already linked"
    casts[cast_id].movies.append(movie_id)
    movies[movie_id].casts.append(cast_id)
    return f"successfully linked {cast_id} to {movie_id}"

def filter_movies_by_title(pattern):
    global movies 
    filtered_movies = []
    for id, movie in movies.items():
        if movie.title.startswith(pattern):
            filtered_movies.append(id)
    filtered_movies.sort()
    return filtered_movies

def filter_movies_by_date(ineq, n):
    global movies 
    cmp = None 
    if ineq == "<=":
        cmp = lambda x,y: x <= y
    elif ineq == "<":
        cmp = lambda x,y: x < y
    elif ineq == ">=":
        cmp = lambda x,y: x >= y
    elif ineq == ">":
        cmp = lambda x,y: x > y
    else:
        cmp = lambda x,y: x == y 
    filtered_movies = []
    for id, movie in movies.items():
        if cmp(movie.date, n):
            filtered_movies.append(id)
    filtered_movies.sort()
    return filtered_movies

def filter_movies_by_quality(pattern):
    global movies 
    filtered_movies = []
    for id, movie in movies.items():
        if movie.quality == pattern:
            filtered_movies.append(id)
    filtered_movies.sort()
    return filtered_movies

q = int(input())
answers = []
for i in range(q):
    args = input().split()
    if args[0] == "ADD-MOVIE":
        answers.append(add_movie(args[1], args[2], args[3]))
    elif args[0] == "REM-MOVIE":
        answers.append(rem_movie(int(args[1])))
    elif args[0] == "ADD-CAST":
        answers.append(add_cast(args[1]))
    elif args[0] == "REM-CAST":
        answers.append(rem_cast(int(args[1])))
    elif args[0] == "LINK-CAST-TO-MOVIE":
        answers.append(link_cast_to_movie(int(args[1]), int(args[2])))
    elif args[0] == "SHOW-MOVIE":
        answers.append(show_movie(int(args[1])))
    elif args[0] == "SHOW-CAST":
        answers.append(show_cast(int(args[1])))
    elif args[0] == "FILTER-MOVIES-BY-TITLE":
        answers.append(str(filter_movies_by_title(args[1])))
    elif args[0] == "FILTER-MOVIES-BY-DATE":
        answers.append(str(filter_movies_by_date(args[1], int(args[2]))))
    elif args[0] == "FILTER-MOVIES-BY-QUALITY":
        answers.append(str(filter_movies_by_quality(args[1])))

for ans in answers:
    print(ans)
