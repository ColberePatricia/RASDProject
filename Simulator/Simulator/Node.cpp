#include "Node.h"


Node::Node(int nbTraditionalNodes = 64, int nbAcceleratedNodes = 32, int nbSpecializedNodes = 32) {
	nbOfTraditionalNodes = nbTraditionalNodes;
	nbOfAcceleratedNodes = nbAcceleratedNodes;
	nbOfSpecializedNodes = nbSpecializedNodes;

	nbOfHoursPerWeek = 80;

	// The matrix is initialised to contain zeros, so the nodes are initialised to be free
	traditionalNodes =  Matrix(nbOfHoursPerWeek, nbOfTraditionalNodes);
	acceleratedNodes = Matrix(nbOfHoursPerWeek, nbOfAcceleratedNodes);
	specializedNodes = Matrix(nbOfHoursPerWeek, nbOfSpecializedNodes);
}

