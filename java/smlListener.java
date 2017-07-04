// Generated from sml.g4 by ANTLR 4.7
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link smlParser}.
 */
public interface smlListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link smlParser#commandSeq}.
	 * @param ctx the parse tree
	 */
	void enterCommandSeq(smlParser.CommandSeqContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#commandSeq}.
	 * @param ctx the parse tree
	 */
	void exitCommandSeq(smlParser.CommandSeqContext ctx);
	/**
	 * Enter a parse tree produced by {@link smlParser#command}.
	 * @param ctx the parse tree
	 */
	void enterCommand(smlParser.CommandContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#command}.
	 * @param ctx the parse tree
	 */
	void exitCommand(smlParser.CommandContext ctx);
	/**
	 * Enter a parse tree produced by {@link smlParser#declaration}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration(smlParser.DeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#declaration}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration(smlParser.DeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link smlParser#varType}.
	 * @param ctx the parse tree
	 */
	void enterVarType(smlParser.VarTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#varType}.
	 * @param ctx the parse tree
	 */
	void exitVarType(smlParser.VarTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link smlParser#assignment}.
	 * @param ctx the parse tree
	 */
	void enterAssignment(smlParser.AssignmentContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#assignment}.
	 * @param ctx the parse tree
	 */
	void exitAssignment(smlParser.AssignmentContext ctx);
	/**
	 * Enter a parse tree produced by {@link smlParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(smlParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(smlParser.ExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link smlParser#arithExpr}.
	 * @param ctx the parse tree
	 */
	void enterArithExpr(smlParser.ArithExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#arithExpr}.
	 * @param ctx the parse tree
	 */
	void exitArithExpr(smlParser.ArithExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link smlParser#boolExpr}.
	 * @param ctx the parse tree
	 */
	void enterBoolExpr(smlParser.BoolExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#boolExpr}.
	 * @param ctx the parse tree
	 */
	void exitBoolExpr(smlParser.BoolExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link smlParser#conditionalExpr}.
	 * @param ctx the parse tree
	 */
	void enterConditionalExpr(smlParser.ConditionalExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#conditionalExpr}.
	 * @param ctx the parse tree
	 */
	void exitConditionalExpr(smlParser.ConditionalExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link smlParser#inputExpr}.
	 * @param ctx the parse tree
	 */
	void enterInputExpr(smlParser.InputExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#inputExpr}.
	 * @param ctx the parse tree
	 */
	void exitInputExpr(smlParser.InputExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link smlParser#output}.
	 * @param ctx the parse tree
	 */
	void enterOutput(smlParser.OutputContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#output}.
	 * @param ctx the parse tree
	 */
	void exitOutput(smlParser.OutputContext ctx);
}