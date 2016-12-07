# sakura_morse_balus

[バルス](https://ja.wikipedia.org/wiki/飛行石#.E3.81.8A.E3.81.BE.E3.81.98.E3.81.AA.E3.81.84)をさくらのクラウド上で実装するためのソフトウェアパーツ for Arduino

## 概要

このプロジェクトは、さくらのクラウド上に「バルス」を実装するためのソフトウェアパーツです。

以下のように動作します。

  - 1) [さくらのIoT Platform](https://iot.sakura.ad.jp)からOutgoing Webhookで指示をもらう
  - 2) [sacloud-delete-all](https://github.com/yamamoto-febc/sacloud-delete-all)にてクラウド上のリソースを全削除
  - 3) 削除結果(正常終了/異常終了)をさくらのIoT Platformを利用して通知(Incoming Webhook)

サーバー側プロジェクトは以下のリポジトリです。

[sacloud-balus](https://github.com/yamamoto-febc/sacloud-balus)

## License

 `sakura_morse_balus` Copyright (C) 2016 Kazumichi Yamamoto.

  This project is published under [Apache 2.0 License](LICENSE.txt).
  
## Author

  * Kazumichi Yamamoto ([@yamamoto-febc](https://github.com/yamamoto-febc))

