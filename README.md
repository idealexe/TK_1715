# Melody Maker

[![Product Name](https://raw.github.com/GabLeRoux/WebMole/master/ressources/WebMole_Youtube_Video.png)](https://www.youtube.com/channel/UC4PtjOfZTbVp9DwtJv82Lzg)

## 製品概要
### :notes: sound design Tech :notes:

### 背景
- 背景

 普段目に見えないデータを音に変換することで、これまでに聞いたことのない音色の変化や楽曲を自動生成したかった．

　” That’s what I love about music.  
 One of the most banal scenes is suddenly invested… with so much meaning.”  はじまりのうた　
 
 
- 着目した顧客・顧客の課題・現状　　

  着目した顧客：
  
   1．音楽を演奏する人　楽器としての利用  
   2．音楽を聴く人 環境に合わせたBGM  
   3．音楽の利用者　使用量が発生しないBGM  
  
  現状と課題：  
  可聴化の研究はされているが，楽曲として楽しめるものがない  　
  参考文献：http://sonification.de/publications/media/Hermann2008-TAD.pdf
  
  センサー値を楽しめる形へ可聴化
  
  演奏家が使えるような実用的プロフダクトの作成 
　
### 製品説明（具体的な製品の説明）
### 特長
* 特長1
音と関係ないデータを可聴化し音楽を自動で生成します
コードのデータベースを作成し，マルコフ連鎖によってコードを遷移させる．  
コードトーンを引数に取り，メロディやベースの音を追加することによって音楽が自動生成される．

* 特長2
楽器として利用可能です  
センサを用い環境にあったコード群の選択や音色の変化を行う．

* 特長3
心地よさを感じるサウンドメイキング
AIを用いて環境にコグニティブなサウンドメイキングを可能にする．

### 解決出来ること
使用量が発生しないBGM

### 今後の展望
楽器として楽しめるUI  
他の楽器との同期  
拡張性の向上（ネット上のデータを利用）  
MIDIをデータ出力して外部音源と連携  
生成アルゴリズムの改善 
AIを用いた心地よいサウンドメイキング

## 開発内容・開発技術
### 活用した技術
#### API・データ
  
#### フレームワーク・ライブラリ・モジュール
* The Synthesis tookkit
* WiringPi
#### デバイス
* raspberry pi2
* ジャイロ、温度、カメラセンサー
#### 設計ツール
* Fusion 360
### 研究内容・事前開発プロダクト（任意）

### 独自開発技術（Hack Dayで開発したもの）
#### 2日間に開発した独自の機能・技術
* 美しいデザインの筐体
* マルコフ連鎖に基づいた拡張性のあるサウンド生成アルゴリズム
* 特に力を入れた部分をファイルリンク、またはcommit_idを記載してください（任意）
