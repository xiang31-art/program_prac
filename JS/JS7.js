// ===== 簡易電卓 =====

function calculate(a, operator, b) {
  switch (operator) {
    case "+":
      return a + b;
    case "-":
      return a - b;
    case "*":
      return a * b;
    case "/":
      if (b === 0) {
        return "エラー：0で割ることはできません";
      }
      return a / b;
    default:
      return "エラー：不明な演算子です";
  }
}

function showResult(a, operator, b) {
  const result = calculate(a, operator, b);
  console.log(`${a} ${operator} ${b} = ${result}`);
}

// 動作確認
showResult(10, "+", 3);
showResult(10, "-", 3);
showResult(10, "*", 3);
showResult(10, "/", 3);
showResult(10, "/", 0);
showResult(10, "%", 3);
