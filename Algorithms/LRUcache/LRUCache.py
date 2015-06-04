class LRUCache:
    # @param capacity, an integer
    def __init__(self, capacity):
        self.capacity = capacity
        self.queue = [] # hold keys.
        self.value = {} # key to value mapping.

    # @return an integer
    def get(self, key):
        if key in self.value:
            idx = self.queue.index(key)
            del self.queue[idx]
            self.queue.insert(0, key)
            return self.value[key]
        return -1

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
        if key in self.value:
            idx = self.queue.index(key)
            del self.queue[idx]
        elif len(self.queue) == self.capacity:
                ok = self.queue.pop() # oldest key
                del self.value[ok]
        self.queue.insert(0, key)
        self.value[key] = value

    def dump(self):
        print "queue: ", self.queue
        print "value: ", self.value
#Test:
c = None

def get(key):
    v = c.get(key)
    print "get", key, "=>", v
    c.dump()

def set(key, value):
    print "set", key, value
    c.set(key, value)
    c.dump()

c = LRUCache(2)
set(2,1)
set(2,2)
get(2)
set(1,1)
set(4,1)
get(2)
