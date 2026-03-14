//モジュール読み込み
const express = require('express');
const cors = require('cors');
const fs = require('fs');
const { resourceUsage } = require('process');

//Expressアプリ作成
const app = express();

//CORS設定（フロントエンドからのアクセス設定）
app.use(cors());

//JSONファイル読み込み
const cpusData = JSON.parse(fs.readFileSync('./cpus.json', 'utf-8'));

//エンドポイント:全県取得
app.get('/api/cpus', (req, res) => {
    //cpuDataをそのまま返す
    res.json(cpusData);
});

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
        results = results.filter(cpu => cpu.maker);
    }

    //グレードフィルター
    if (grade) {
        results = results.filter(cpu => cpu.grade);
    }

    res.json(results);
});