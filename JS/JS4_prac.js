// ==== 簡易クイズアプリ ====

const quizzes = [   //クイズ問題集
    { question: "JavaScriptの配列の要素数を取得するプロパティは？", answer: "length" },
    { question: "コンソールに出力する関数は？", answer: "console.log" },
    { question: "配列の末尾に要素を追加するメソッドは？", answer: "push" },
    { question: "小数点以下を切り捨てる関数は？", answer: "Math.floor" },
    { question: "JavaScriptで厳密に等しいか比較する演算子は？", answer: "==="}
]

function askQuestion(quiz, number) {    //クイズ出題関数
    console.log(`Q${number}: ${quiz.question}`);    //クイズ番号、問題文出力
    console.log(`あなたの回答：${quiz.answer}`);    //回答入力を促す表示
}

function runQuiz() {    //クイズ実行関数。cのmain関数的存在
    let score = 0;      //ユーザーの正解数カウント

    for (let i = 0; i < quizzes.length; i++) {  //クイズ全問出題ループ
        askQuestion(quizzes[i], i + 1);         //クイズ出題

        const correct = quizzes[i].answer;    //正答を比較するため
        const userAnswer = correct;                     //ユーザー回答を保存(今回はスキップ)

        if (userAnswer === correct) {   //正解か判定
            console.log("→ 正解！");    //正解したことを表示
            score++;                     //スコアを増やす
        } else {        //正解でなければ分岐する。(今回は分岐先が2つしかないので "else if" ではない)
            console.log(`→ 不正解… 正解は「${correct}」`);  //不正解であることを表示
        }
    }
    console.log("");    //空行(出力整形のため)

    console.log("==== 結果 ======");    //結果表示タイトル
    console.log(`${quizzes.length}問中 ${score}問正解`);    //テンプレートリテラルによる正答数出力
    console.log(`正答率：${Math.floor(score / quizzes.length * 100)}%`); //正答率を計算し出力
}

//動作確認
runQuiz();