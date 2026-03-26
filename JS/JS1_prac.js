// === TODOリスト簡易版 ===

const todos = [];

function addTodo(task){
    todos.push(task);
    console.log(`「${task}」を追加しました`);
}

function removeTodo(index){
    if (index < 0 || index >= todos.length){
        console.log("その番号のタスクは存在しません");
        return;
    }
    const removed = todos.splice(index, 1);
    console.log(`「${removed[0]}」を削除しました`);
}

function showTodos() {
    if (todos.length === 0){
        console.log("タスクはありません");
        return;
    }
    console.log("----- ToDoリスト -----");
    for (let i = 0; i < todos.length; i++){
        console.log(`${i}:${todos[i]}`);
    }
    console.log("----------------------");
}

addTodo("買い物");
addTodo("JS勉強");
addTodo("部屋の掃除");

showTodos();

removeTodo(1);
showTodos();