# InputGenerator
Generating labeling instances as a set of 2D points in a bounded plane.<br />
Format (like DIMACS FORMAT)<br />
Files are assumed to be well-formed and internally consistent: coordinates are valid (inside the plane range), points are defined uniquely (different pairs of coordinates).<br />  
## Comment line:

Comment lines give human-readable information about the file and are ignored by programs.<br /> 
Comment lines can appear at beginning in the file. <br />
Each comment line begins with a lower-case character c. <br />
c This is an example of a comment line.<br />

## Problem line:

There is one problem line per input file. The problem line must appear before any descriptor lines. The problem line has the following format. <br />
The lower-case character p signifies that this is the problem line. The FORMAT field is for specifiying different Categories, and should contain the word "UNWEIGHTED", "WEIGHTED" and so on. The field number_of_nodes should be consitently egal to the number of Descriptor lines.<br />
p FORMAT number_of_nodes plane_width plane_height<br />


## Descriptor line:

There is one descriptor line for each point element, each with the following format. Each point (x,y) of weight w appears exactly once in the input file. <br />
The lower-case character e signifies that this is an element descriptor line.<br /> 
e x y w <br />
