# Robot War Game

Takes in file input `start.txt` in the format:

`id team x-pos y-pos` and each line is a new robot.

`commands.txt` is where commands for each robot is written.

Commands are of follows:
`show` - show a list of all robots (sorted by robot ID).
`travelled` - show a list of robots (sorted by distance travelled).
`move n` - moves robot with the ID `n` in the direction it is facing.
`within n` - list of robots within `n` units away from the origin.
`turnright n` - turn robot with id `n` right *(i.e North -> East facing)*.
`turnleft n` - turn robot with id `n` left *(i.e North -> West facing)*.
