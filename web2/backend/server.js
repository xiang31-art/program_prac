//モジュール読み込み
const express = require('express');
const cors = require('cors');
const fs = require('fs');

//Expressアプリ作成
const app = express();

//CORS設定（フロントエンドからのアクセス設定）
app.use(cors());

//JSONファイル読み込み
const cpusData = JSON.parse(fs.readFileSync('./cpus.json', 'utf-8'));

//エンドポイント:全件取得
app.get('/api/cpus', (req, res) => {
    //cpuDataをそのまま返す
    res.json(cpusData);
});

//エンドポイント:検索・フィルター
app.get('/api/cpus/search', (req, res) => {
    //クエリパラメータの取得
    const {keyword, maker, grade } = req.query;

    //フィルタリング処理
    let results = cpusData;

    //キーワード検索
    if (keyword) {
        results = results.filter(cpu => cpu.modelName.toLowerCase().includes(keyword));
    }

    //メーカーフィルター
    if (maker) {
        results = results.filter(cpu => cpu.maker === maker);
    }

    //グレードフィルター
    if (grade) {
        results = results.filter(cpu => cpu.grade === grade);
    }

    res.json(results);
});

//エンドポイント:詳細情報取得
app.get('/api/cpus/:id', (req, res) => {
    const id = parseInt(req.params.id);
    const cpu = cpusData.find(cpu => cpu.id === id);

    if (cpu) {
        res.json(cpu);
    } else {
        res.status(404).json({ error: 'CPU not found' });
    }
});

//サーバー起動
const PORT = 3001;
app.listen(PORT, () =>{
    console.log(`Server is running on http://localhost:${PORT}`);
});