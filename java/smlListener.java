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
	 * Enter a parse tree produced by {@link smlParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(smlParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(smlParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link smlParser#blockComm}.
	 * @param ctx the parse tree
	 */
	void enterBlockComm(smlParser.BlockCommContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#blockComm}.
	 * @param ctx the parse tree
	 */
	void exitBlockComm(smlParser.BlockCommContext ctx);
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
	 * Enter a parse tree produced by {@link smlParser#arrDecl}.
	 * @param ctx the parse tree
	 */
	void enterArrDecl(smlParser.ArrDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#arrDecl}.
	 * @param ctx the parse tree
	 */
	void exitArrDecl(smlParser.ArrDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link smlParser#intRef}.
	 * @param ctx the parse tree
	 */
	void enterIntRef(smlParser.IntRefContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#intRef}.
	 * @param ctx the parse tree
	 */
	void exitIntRef(smlParser.IntRefContext ctx);
	/**
	 * Enter a parse tree produced by {@link smlParser#arrExpr}.
	 * @param ctx the parse tree
	 */
	void enterArrExpr(smlParser.ArrExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#arrExpr}.
	 * @param ctx the parse tree
	 */
	void exitArrExpr(smlParser.ArrExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link smlParser#intIdRef}.
	 * @param ctx the parse tree
	 */
	void enterIntIdRef(smlParser.IntIdRefContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#intIdRef}.
	 * @param ctx the parse tree
	 */
	void exitIntIdRef(smlParser.IntIdRefContext ctx);
	/**
	 * Enter a parse tree produced by {@link smlParser#forLoop}.
	 * @param ctx the parse tree
	 */
	void enterForLoop(smlParser.ForLoopContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#forLoop}.
	 * @param ctx the parse tree
	 */
	void exitForLoop(smlParser.ForLoopContext ctx);
	/**
	 * Enter a parse tree produced by {@link smlParser#rangeList}.
	 * @param ctx the parse tree
	 */
	void enterRangeList(smlParser.RangeListContext ctx);
	/**
	 * Exit a parse tree produced by {@link smlParser#rangeList}.
	 * @param ctx the parse tree
	 */
	void exitRangeList(smlParser.RangeListContext ctx);
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