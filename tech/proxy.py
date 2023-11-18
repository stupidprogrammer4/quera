class Proxy:
    def __init__(self, obj):
        self._obj = obj
        self._last_invoked_method = ''
        self.calls = {}

    def __update_log(self, attr):
        if self.calls.get(attr):
            self.calls[attr] += 1
        else:
            self.calls[attr] = 1
        self._last_invoked_method = attr

    def last_invoked_method(self):
        if not self._last_invoked_method:
            raise Exception('No Method Is Invoked')
        return self._last_invoked_method

    def count_of_calls(self, method_name):
        return self.calls[method_name] if self.calls.get(method_name) else 0

    def was_called(self, method_name):
        return self.calls.get(method_name) is not None
    
    def __getattr__(self, method):
        methods = [method_name for method_name in dir(self._obj)]
        if method in methods:
            self.__update_log(method)
            return getattr(self._obj, method)
        raise Exception('No Such Method')
