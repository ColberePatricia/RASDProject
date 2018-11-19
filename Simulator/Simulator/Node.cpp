#include "Node.h"


Node::Node(int nbCoresPerTraditionalNode = 16, int nbCoresPerAcceleratedNode = 16, int nbCoresPerSpecializedNode = 16, int nbTraditionalNodes = 64, int nbAcceleratedNodes = 32, int nbSpecializedNodes = 32) {
	nbOfProcessorCoresTraditional = nbCoresPerTraditionalNode * nbTraditionalNodes;
	nbOfProcessorCoresAccelerated= nbCoresPerAcceleratedNode * nbAcceleratedNodes;
	nbOfProcessorCoresSpecialized = nbCoresPerSpecializedNode * nbSpecializedNodes;
	nbOfTraditionalNodes = nbTraditionalNodes;
	nbOfAcceleratedNodes = nbAcceleratedNodes;
	nbOfSpecializedNodes = nbSpecializedNodes;
}

