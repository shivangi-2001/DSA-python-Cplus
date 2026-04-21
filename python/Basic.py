from typing import List

class Car:
    def __init__(self, brand: str, model: str):
        self.brand = brand
        self.model = model
        self.speed = 0.0
        
    def accelerate(self, speed: float) -> float:
        self.speed += speed
        return self.speed
        
    def display_status(self) -> None:
        print("Driving")
        
        
if __name__ == '__main__':
    corolla = Car("Toyota", "Corolla")
    mustang = Car("Ford", "Mustang")

    print(corolla.accelerate(20))
    print(mustang.accelerate(40))

    # Displaying status of each car
    corolla.display_status()
    print("-----------------")
    mustang.display_status()
    
        