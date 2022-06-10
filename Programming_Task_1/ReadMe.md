# Follow Me
Follow Me is a task in which several clips are played according to some specific actions based on the number of ticks mentioned through the commands. There are only two types of commands.

1. Clip
2. Ticks

## Clip
The clip command is use for storing specific actions and later on these actions are performed based on the number of ticks supplied through the ticks command.

The format of clip command is shown below    
`clip <name> <ticks to play> <chance1> <chance2> <action1> <action2>`   

`<name>` specifies the name of the clip     
`<ticks to play>` specifies the number of times the name of the clip is printed     
`<chance1>` specifies the chance of first action to perform     
`<chance2>` specifies the chance of second action to perform        
`<action1>` specifies the first action      
`<action2>` specifies the second action

The chances provided in this command can be referred to as probability of occurrence with respect to each other.

## Ticks
The ticks command specifies the number of times the name of the clip is to be printed. However, some floating numbers can be added in the end of the command in the form of pairs. The number of pairs is equal to the number of total ticks passed in the same command. If the number of pairs and ticks to play figure does not match, then an error code(127) is generated.

The format of ticks command is shown below
`ticks <ticks to play> <optional list of floating point numbers>`

## Action
The possible values for action are

1. `none` Nothing happens – the clip keeps playing. 
2. `any` Any clip (including the playing one) can be triggered (at random). 
3. `other` Any other clip can be triggered (at random). 
4. `next` The next clip (in the order they were created) will be triggered. 
5. `previous` The previous clip will be triggered.

However, when the end is reached, the clip collection will act as a circular buffer and on incrementing one more time the accessed clip would be the first clip of the clip collection. If a clip is created with the same name as an existing clip, the new clip should replace the
existing clip. With every ticks command, the playback should advance the number of steps given. The
very first ticks command will always trigger the first clip.

# Requirements
The requirements for this project is to have a Linux environment. After that, try installing doctest package by using the following command

`sudo apt install doctest-dev`

This package is used for unit testing and is known to be a lightweight implementation of Catch2 unit test setup. In order to execute the unit tests made in this project, this is a necessary requirement. This project was made on CLion with CMake project requirements.

# Algorithm
The algorithm can be explained in a few steps

1. Taking input of all commands
2. Storing commands in a container
3. Parsing commands to analyze 'clip' and 'ticks' commands
4. Parsing 'ticks' and 'clip' commands
5. Calculating probability according to the given chances in the 'clip' command
6. Performing action

The first step comprises giving all the commands in the input. The commands are seperated by new line. When we want to conclude the process of giving input commands, press the enter key without writing anything. In this way, the program will start to execute.

The second step consists of the program storing commands in a container. This container will have the collection of all the commands. In this scenario, I have used a queue.

The third step tells us about the separation of the "clip" and "ticks" commands. This is done on the basis of command type stored at the first index of each command.

The fourth step lets us know the conditions of the "ticks" and "clip" commands. A global variable is maintained for the total number of ticks given in the "ticks" commands. Some booleans, floats and unsigned integers are used for storing the aspects of a clip given in the clip command.

The fifth step is all about calculating the probability according to the given chances as input in the "clip" command. According to these probabilities, the actions are performed. These probabilities are calculated using the random number generation method. A random number is generated between the range of one to higher chance value. If the generated number is lower or equal to the lower chance value, the action associated with the lower chance is executed. Otherwise, the action associated with the higher chance is executed. Booleans are used to differentiate the behavior of `any` and `other` actions.

The sixth step just executes and returns the string in which the proper formatted output is written which is later displayed through standard output.


# Unit Testing
In order to run the unit tests, first you should have installed doctest. Second, in the current **CMakeLists.txt** file
```
cmake_minimum_required(VERSION 3.16)

project(Programming_Task_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programming_Task_1
        main.cpp
#        unittest.cpp
        )
```

In this **CMakeLists.txt** file, just replace the line `main.cpp` with `#   main.cpp`, and `#   unittest.cpp` with `unittest.cpp`. After doing this, just execute the code. The relevant logs of unittest will be displayed on the screen.