// === 数あてゲーム ===

function generateAnswer(max) {  //当てる数を生成する関数
    return Math.floor(Math.random() * max) + 1; //1~10の数を生成
}

function checkGuess(guess, answer) {    //ユーザーの回答が等しいか判定
    if (guess === answer) { //ユーザーの回答が正解である場合
        return "correct";   //等しいことを出力
    }
    if (guess > answer) {   //ユーザーの回答が大きい場合
        return "high";      //大きいことを出力
    }   //ユーザの回答が小さい場合(早期リターン)
        return "low";       //小さいことを出力
}

function 