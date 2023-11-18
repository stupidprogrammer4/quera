ls = [int, float]

class Chain:
    def __init__(self, value):
        self.value = value
        t = type(value)
        if t not in ls and t != str:
            raise Exception('invalid operation')
        if t in ls:
            t = 'number'
        self.t = t
    def __call__(self, value):
        t = type(value)
        if t in ls:
            t = 'number'
        if t != self.t:
            raise Exception('invalid operation')
        if t == str:
            value = ' ' + value
        self.value += value 
        return self
    def __repr__(self):
        if self.t == 'number':
            if self.value == int(self.value):
                return str(int(self.value))
            else:
                return str(self.value)
        return f"'{self.value}'"
    def __eq__(self, other):
        return self.value == other
