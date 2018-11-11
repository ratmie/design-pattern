class Duck:
    def __init__(self):
    	self.quackBehavior

    def performQuack(self):
        self.quackBehavior()
    
    def setQuackBehavior(self,f):
        self.quackBehavior = f

def quack():
    print("ガーガー")

def muteQuack():
    print("<沈黙>")

class MallardDuck(Duck):
    def __init__(self):
        self.quackBehavior = quack

mallard = MallardDuck()
mallard.performQuack()
mallard.setQuackBehavior(muteQuack)
mallard.performQuack()