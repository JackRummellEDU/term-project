#include "NumberNode.h"

NumberNode::NumberNode(double value) : value_(value) {
}

double NumberNode::evaluate() const {
  return value_;
}