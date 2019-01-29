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

states = ["head", "tail"]

ps = EqualProbProcess(states)
print(ps.getStates())

dice = ["1", "2","3","4","5","6"]
ps = EqualProbProcess(dice)
print(ps.getStates(20))
