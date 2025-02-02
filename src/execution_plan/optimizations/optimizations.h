/*
* Copyright 2018-2021 Redis Labs Ltd. and Contributors
*
* This file is available under the Redis Labs Source Available License Agreement
*/

#pragma once

#include "../execution_plan.h"
#include "../../filter_tree/filter_tree.h"
#include "../../arithmetic/algebraic_expression.h"

// reorders exps such that exp[i] is the ith expression to evaluate
void orderExpressions(
	QueryGraph *qg,                 // queryGraph containing expression entity data
	AlgebraicExpression **exps,     // expressions to order
	uint *exps_count,               // number of expressions
	const FT_FilterNode *filters,   // filters
	rax *bound_vars                 // previously-bound variables
);

void compactFilters(ExecutionPlan *plan);
void reduceScans(ExecutionPlan *plan);
void utilizeIndices(ExecutionPlan *plan);
void seekByID(ExecutionPlan *plan);
void filterVariableLengthEdges(ExecutionPlan *plan);
void reduceCartesianProductStreamCount(ExecutionPlan *plan);
void applyJoin(ExecutionPlan *plan);
void reduceFilters(ExecutionPlan *plan);
void reduceTraversal(ExecutionPlan *plan);
void reduceDistinct(ExecutionPlan *plan);
void reduceCount(ExecutionPlan *plan);
void applyLimit(ExecutionPlan *plan);
void applySkip(ExecutionPlan *plan);
void optimizeLabelScan(ExecutionPlan *plan);

