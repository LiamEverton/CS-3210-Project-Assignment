# CS 3210 Course Project

## Project Assignment
https://github.com/uiowa-cs-3210-0001/cs3210-assignments/tree/master/course-project

## Grading Assumptions

-- The program would be able to meet all stretch goals very easily, if given more time to do so.

-- Documentation and code comments would be taken into consideration for extra credit, even though it wasn't specified in the original rubric.

-- I allowed for unconventional map input by padding the ending, since some text editors remove additional whitespace after a character.

## Project Assumptions

-- Energy is expended, even if a valid action (grow, consume, move, reproduce) cannot be made.

-- Each type of action is possible during an Iteration by each Organism.

-- Reproduced animals instantly enter the world and can continue to reproduce in the same Iteration.

## Developer Documentation
This system is designed so that the implementation can continue beyond this base.

For example, many different organism types can be added in the future with ease, a Simulation could house many EcoSystems and allow for interaction between the two.

I wanted to keep the possibilities of this project limitless, so that the codebase would be valuable in the long-term, even further than persuant of the extension tasks.

My comments should be enough, but here is some justifications of some of the classes, incase you were interested.

### EntityType
I chose to include a EntityType to avoid boxing/casting issues, as it seemed an inherit design flaw to rely on casting.

An interesting finding when looking into this principle: my code would otherwise violate the Liskov substitution principle.

### Iteration
I chose to separate the changing of the EcoSystem from the data/model classes, so there was a very clear cut write and read in the simulation, as opposed to a very messy and unclean implementation being found in each class.

I wanted to make it extremely transparent as to what classes are manipulating data. I did this by passing in the Iteration into the necessary classes, so that Organism's could remain untied from an EcoSystem.

### Entity
I used a list of Entities over strictly a 2d map, so that there can be multiple entities in one location, such as the case of an alive animal, but a dead plant.

I decided to keep the 2d map in the final implementation, for quick access to displaying the current state of the map. When an update occurs between the Entities, I update the 2d map, so that the output can remain quick. Ultimately, I didn't want to continuously sort the list using position because way too inefficient.

### Species and Organisms
Species are dynamic, the user should be able to create new Species at will, but new implementations of Organisms cannot be dynamically created, as they have unique properties and functionality.

This is why i was able to hard code EntityTypes while keeping Species simply a dynamic input, used for simulation creation.

### Input
I decided to hard code the processing of inputs, as opposed to trying to make a dynamic solution, strictly because I didn't feel like it was ultimately necessary. Every project has time limits and I felt like this would be necessary more so for larger games with a much larger collection of different inputs.
