class Shooter:

    def __init__(self):
        self.damage = None
        self.power = None
        self.shooting_range = None
        self.bullet_count = None
        self.bullet_size = None
        self.name = None

    def set_gun_by_name(self, name: str) -> None:
        guns = ["Submachine Gun", "Assault Rifle", "Pistol", "Shotgun", "Sniper Rifle"]
        if name not in guns:
            raise Exception
        else:
            self.name = name
            if name == "Submachine Gun":
                self.shooting_range = 100
                self.power = 10
                self.bullet_size = 0.5
            elif name == "Assault Rifle":
                self.shooting_range = 200
                self.power = 20
                self.bullet_size = 1
            elif name == "Pistol":
                self.shooting_range = 80
                self.power = 8
                self.bullet_size = 0.5
            elif name == "Shotgun":
                self.shooting_range = 50
                self.power = 40
                self.bullet_size = 4
            elif name == "Sniper Rifle":
                self.shooting_range = 1000
                self.power = 30
                self.bullet_size = 3

    def add_bullet_of_given_size_to_gun(self, size: float, count: int) -> None:
        if (not self.name) or self.bullet_size != size or count < 0 or size not in [1, 3, 4, 0.5]:
            raise Exception
        else:
            self.bullet_size = size
            self.bullet_count = count
            if self.bullet_size == 0.5:
                self.damage = 1
            elif self.bullet_size == 1:
                self.damage = 1.5
            elif self.bullet_size == 3:
                self.damage = 3
            elif self.bullet_size == 4:
                self.damage = 2

    def shoot_to_target(self, target_x: int,  target_y: int,  target_distance: int,  aim_x: int,  aim_y: int) -> float:
        if (not self.name) or (self.bullet_count == 0):
            raise Exception
        elif (aim_x > target_x + 10 or aim_x < target_x) or (aim_y > target_y + 10 or aim_y < target_y):
            self.bullet_count = self.bullet_count - 1
            self.name = ""
            return 0
        elif self.shooting_range < target_distance:
            self.bullet_count = self.bullet_count - 1
            self.name = ""
            return 0
        else:
            self.bullet_count = self.bullet_count - 1
            self.name = ""
            return self.damage * self