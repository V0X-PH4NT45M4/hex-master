from enum import StrEnum
from collections import Counter, deque

# the goal is to generate some visualizations for the transformed coordinate system
# the (q, r) coordinate system for catan will have 
# -10 <= q, r <= 10
# we want to populate matrix of size [20][20]

class catan_coordinate_system:
    class component(StrEnum):
        TILE = 'T'
        EDGE = 'E'
        POINT = 'P'
        SENTINEL = '0'

    def __init__(self, layers: int):
        # using a dictionary to use (q, r) as identifiers
        self.system = {}
        self.offset = 10

        # we must BFS from root layer
        visited = set()
        neighbor_offsets = [(2,2),(-2,-2),(4,-2),(-2,4),(-4,2),(2,-4)]
        queue = deque([(0, 0)])

        for layer in range(layers):
            next_queue = deque()
            while queue:
                q, r = queue.pop()
                if (q, r) in visited:
                    continue
                visited.add((q, r))
                self.add_hex(q, r)

                for dq, dr in neighbor_offsets:
                    next_queue.append(((q + dq), (r + dr)))
            queue = next_queue


    # visualize entries in a 21 x 21 grid
    # coordinates will be added by offset to make them unsigned
    def visualize(self):
        for q in range(21):
            for r in range(21):
                if (q - self.offset, r - self.offset) in self.system:
                    print(self.system[(q - self.offset, r - self.offset)].value, end='')
                else:
                    print(self.component.SENTINEL.value, end='')
            print('')
        print('\n')

    # add coordinates for all edges and points and the TILE itself, centered at (q,r)
    def add_hex(self, q, r):
        # the TILE itself 
        self.system[(q, r)] = self.component.TILE

        # the vertices surrounding the tile
        self.system[(q+2,r+0)]=self.component.POINT
        self.system[(q+2,r-2)]=self.component.POINT
        self.system[(q+0,r+2)]=self.component.POINT
        self.system[(q+0,r-2)]=self.component.POINT
        self.system[(q-2,r+2)]=self.component.POINT
        self.system[(q-2,r+0)]=self.component.POINT
        
        # the edges surrounding the tile
        self.system[(q+1,r+1)]=self.component.EDGE
        self.system[(q-1,r-1)]=self.component.EDGE
        self.system[(q+2,r-1)]=self.component.EDGE
        self.system[(q-1,r+2)]=self.component.EDGE
        self.system[(q+1,r-2)]=self.component.EDGE
        self.system[(q-2,r+1)]=self.component.EDGE
        
if __name__ == '__main__':
    board = catan_coordinate_system(layers=3)
    board.visualize()
    print(len(board.system))
    print(Counter(board.system.values()))
