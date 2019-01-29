import numpy as np

class EqualProbProcess:
    def __init__(self, outcomes):
        self.possibleOutcomes = outcomes
        
        sz = len(outcomes)
        self.probs = np.full(sz, 1.0/sz)

    def print(self):
        print(self.possibleOutcomes)
        print(self.probs)

    def nextState(self):
        return np.random.choice(self.possibleOutcomes, p=self.probs)

    def getStates(self, num = 10):
        serise = []

        for i in range(num):
            serise.append(self.nextState())

        return serise

class MarkovProcess:
    # The first row represents transition probality from the state
    def __init__(self, states, transitionMatrix=[]):
        sz = len(transitionMatrix)
        
        # Cheking for sanity
        if sz != 0 and sz != len(transitionMatrix):
            raise Exception("Invalid Matrix")

        if sz != len(transitionMatrix[0]):
            raise Exception("Invalid Matrix")

        self.states = states
        self.currentStateIndex = 0

    def setCurrentState(self, state):
        return None

    def nextState(self):
        return None

    def getStates(self, num=10):
        chain = []

        for i in range(num):
            chain.append(self.nextState())
        
        return chain

transitionMatrix = [    
    [0.8, 0.19, 0.01],
    [0.2,  0.7,  0.1],
    [0.1,  0.2,  0.7]
]


mkp = MarkovProcess(["Sunny", "Rainy", "Foggy"], transitionMatrix=transitionMatrix)

ps = EqualProbProcess(["head", "tail"])
print(ps.getStates())

ps = EqualProbProcess(["1", "2","3","4","5","6"])
print(ps.getStates(20))
