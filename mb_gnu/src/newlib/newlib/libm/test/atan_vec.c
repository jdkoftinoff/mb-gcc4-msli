#include "test.h"
 one_line_type atan_vec[] = {
{64, 0,123,__LINE__, 0xbfec08aa, 0xe496efa6, 0xbff33333, 0x33333333},			/* -0.87605=f(-1.20000)*/
{64, 0,123,__LINE__, 0xbfebe6ed, 0x93e2de0a, 0xbff30a3d, 0x70a3d70a},			/* -0.87193=f(-1.19000)*/
{64, 0,123,__LINE__, 0xbfebc4da, 0xc279b378, 0xbff2e147, 0xae147ae1},			/* -0.86778=f(-1.18000)*/
{64, 0,123,__LINE__, 0xbfeba271, 0x78241551, 0xbff2b851, 0xeb851eb8},			/* -0.86357=f(-1.17000)*/
{64, 0,123,__LINE__, 0xbfeb7fb0, 0xbad89c3a, 0xbff28f5c, 0x28f5c28f},			/* -0.85933=f(-1.16000)*/
{64, 0,123,__LINE__, 0xbfeb5c97, 0x8ec9f805, 0xbff26666, 0x66666666},			/* -0.85505=f(-1.15000)*/
{64, 0,123,__LINE__, 0xbfeb3924, 0xf6762ef7, 0xbff23d70, 0xa3d70a3d},			/* -0.85072=f(-1.14000)*/
{64, 0,123,__LINE__, 0xbfeb1557, 0xf2b704a7, 0xbff2147a, 0xe147ae14},			/* -0.84635=f(-1.13000)*/
{64, 0,123,__LINE__, 0xbfeaf12f, 0x82d394f5, 0xbff1eb85, 0x1eb851eb},			/* -0.84194=f(-1.12000)*/
{64, 0,123,__LINE__, 0xbfeaccaa, 0xa4932fec, 0xbff1c28f, 0x5c28f5c2},			/* -0.83748=f(-1.11000)*/
{64, 0,123,__LINE__, 0xbfeaa7c8, 0x545183cc, 0xbff19999, 0x99999999},			/* -0.83298=f(-1.10000)*/
{64, 0,123,__LINE__, 0xbfea8287, 0x8d142296, 0xbff170a3, 0xd70a3d70},			/* -0.82843=f(-1.09000)*/
{64, 0,123,__LINE__, 0xbfea5ce7, 0x48a170fd, 0xbff147ae, 0x147ae147},			/* -0.82384=f(-1.08000)*/
{64, 0,123,__LINE__, 0xbfea36e6, 0x7f990cb5, 0xbff11eb8, 0x51eb851e},			/* -0.81920=f(-1.07000)*/
{64, 0,123,__LINE__, 0xbfea1084, 0x298db87a, 0xbff0f5c2, 0x8f5c28f5},			/* -0.81451=f(-1.06000)*/
{64, 0,123,__LINE__, 0xbfe9e9bf, 0x3d20dc70, 0xbff0cccc, 0xcccccccc},			/* -0.80978=f(-1.05000)*/
{64, 0,123,__LINE__, 0xbfe9c296, 0xb01fa9a4, 0xbff0a3d7, 0x0a3d70a3},			/* -0.80500=f(-1.04000)*/
{64, 0,123,__LINE__, 0xbfe99b09, 0x77a1efc6, 0xbff07ae1, 0x47ae147a},			/* -0.80017=f(-1.03000)*/
{64, 0,123,__LINE__, 0xbfe97316, 0x882ab459, 0xbff051eb, 0x851eb851},			/* -0.79529=f(-1.02000)*/
{64, 0,123,__LINE__, 0xbfe94abc, 0xd5ca9ace, 0xbff028f5, 0xc28f5c28},			/* -0.79037=f(-1.01000)*/
{64, 0,123,__LINE__, 0xbfe921fb, 0x54442d17, 0xbfefffff, 0xfffffffe},			/* -0.78539=f(-0.01000)*/
{64, 0,123,__LINE__, 0xbfe8f8d0, 0xf7321466, 0xbfefae14, 0x7ae147ac},			/* -0.78037=f(-0.99000)*/
{64, 0,123,__LINE__, 0xbfe8cf3c, 0xb22f51e4, 0xbfef5c28, 0xf5c28f5a},			/* -0.77529=f(-0.98000)*/
{64, 0,123,__LINE__, 0xbfe8a53d, 0x79018729, 0xbfef0a3d, 0x70a3d708},			/* -0.77017=f(-0.97000)*/
{64, 0,123,__LINE__, 0xbfe87ad2, 0x3fc55e45, 0xbfeeb851, 0xeb851eb6},			/* -0.76499=f(-0.96000)*/
{64, 0,123,__LINE__, 0xbfe84ff9, 0xfb1d212c, 0xbfee6666, 0x66666664},			/* -0.75976=f(-0.95000)*/
{64, 0,123,__LINE__, 0xbfe824b3, 0xa0619018, 0xbfee147a, 0xe147ae12},			/* -0.75448=f(-0.94000)*/
{64, 0,123,__LINE__, 0xbfe7f8fe, 0x25d50679, 0xbfedc28f, 0x5c28f5c0},			/* -0.74914=f(-0.93000)*/
{64, 0,123,__LINE__, 0xbfe7ccd8, 0x82d8fdbc, 0xbfed70a3, 0xd70a3d6e},			/* -0.74375=f(-0.92000)*/
{64, 0,123,__LINE__, 0xbfe7a041, 0xb025fce7, 0xbfed1eb8, 0x51eb851c},			/* -0.73831=f(-0.91000)*/
{64, 0,123,__LINE__, 0xbfe77338, 0xa80603bc, 0xbfeccccc, 0xccccccca},			/* -0.73281=f(-0.90000)*/
{64, 0,123,__LINE__, 0xbfe745bc, 0x66917fae, 0xbfec7ae1, 0x47ae1478},			/* -0.72726=f(-0.89000)*/
{64, 0,123,__LINE__, 0xbfe717cb, 0xe9eed851, 0xbfec28f5, 0xc28f5c26},			/* -0.72165=f(-0.88000)*/
{64, 0,123,__LINE__, 0xbfe6e966, 0x3294a096, 0xbfebd70a, 0x3d70a3d4},			/* -0.71599=f(-0.87000)*/
{64, 0,123,__LINE__, 0xbfe6ba8a, 0x438e7924, 0xbfeb851e, 0xb851eb82},			/* -0.71027=f(-0.86000)*/
{64, 0,123,__LINE__, 0xbfe68b37, 0x22c4afb2, 0xbfeb3333, 0x33333330},			/* -0.70449=f(-0.85000)*/
{64, 0,123,__LINE__, 0xbfe65b6b, 0xd946a619, 0xbfeae147, 0xae147ade},			/* -0.69865=f(-0.84000)*/
{64, 0,123,__LINE__, 0xbfe62b27, 0x73980b0f, 0xbfea8f5c, 0x28f5c28c},			/* -0.69276=f(-0.83000)*/
{64, 0,123,__LINE__, 0xbfe5fa69, 0x0200ed43, 0xbfea3d70, 0xa3d70a3a},			/* -0.68681=f(-0.82000)*/
{64, 0,123,__LINE__, 0xbfe5c92f, 0x98e0b06f, 0xbfe9eb85, 0x1eb851e8},			/* -0.68080=f(-0.81000)*/
{64, 0,123,__LINE__, 0xbfe5977a, 0x5103ea90, 0xbfe99999, 0x99999996},			/* -0.67474=f(-0.80000)*/
{64, 0,123,__LINE__, 0xbfe56548, 0x47fd2dfe, 0xbfe947ae, 0x147ae144},			/* -0.66861=f(-0.79000)*/
{64, 0,123,__LINE__, 0xbfe53298, 0xa080c38a, 0xbfe8f5c2, 0x8f5c28f2},			/* -0.66242=f(-0.78000)*/
{64, 0,123,__LINE__, 0xbfe4ff6a, 0x82c355fd, 0xbfe8a3d7, 0x0a3d70a0},			/* -0.65617=f(-0.77000)*/
{64, 0,123,__LINE__, 0xbfe4cbbd, 0x1cdb8e6d, 0xbfe851eb, 0x851eb84e},			/* -0.64987=f(-0.76000)*/
{64, 0,123,__LINE__, 0xbfe4978f, 0xa3269ede, 0xbfe7ffff, 0xfffffffc},			/* -0.64350=f(-0.75000)*/
{64, 0,123,__LINE__, 0xbfe462e1, 0x50afb65c, 0xbfe7ae14, 0x7ae147aa},			/* -0.63707=f(-0.74000)*/
{64, 0,123,__LINE__, 0xbfe42db1, 0x679a576c, 0xbfe75c28, 0xf5c28f58},			/* -0.63057=f(-0.73000)*/
{64, 0,123,__LINE__, 0xbfe3f7ff, 0x318f8720, 0xbfe70a3d, 0x70a3d706},			/* -0.62402=f(-0.72000)*/
{64, 0,123,__LINE__, 0xbfe3c1ca, 0x002dc874, 0xbfe6b851, 0xeb851eb4},			/* -0.61740=f(-0.71000)*/
{64, 0,123,__LINE__, 0xbfe38b11, 0x2d7bd4aa, 0xbfe66666, 0x66666662},			/* -0.61072=f(-0.70000)*/
{64, 0,123,__LINE__, 0xbfe353d4, 0x1c5dfe64, 0xbfe6147a, 0xe147ae10},			/* -0.60398=f(-0.69000)*/
{64, 0,123,__LINE__, 0xbfe31c12, 0x390e29f6, 0xbfe5c28f, 0x5c28f5be},			/* -0.59717=f(-0.68000)*/
{64, 0,123,__LINE__, 0xbfe2e3ca, 0xf996421a, 0xbfe570a3, 0xd70a3d6c},			/* -0.59030=f(-0.67000)*/
{64, 0,123,__LINE__, 0xbfe2aafd, 0xde4d0c9b, 0xbfe51eb8, 0x51eb851a},			/* -0.58337=f(-0.66000)*/
{63, 0,123,__LINE__, 0xbfe271aa, 0x72553ed1, 0xbfe4cccc, 0xccccccc8},			/* -0.57637=f(-0.65000)*/
{64, 0,123,__LINE__, 0xbfe237d0, 0x4c1eadfe, 0xbfe47ae1, 0x47ae1476},			/* -0.56931=f(-0.64000)*/
{64, 0,123,__LINE__, 0xbfe1fd6f, 0x0de97384, 0xbfe428f5, 0xc28f5c24},			/* -0.56218=f(-0.63000)*/
{62, 0,123,__LINE__, 0xbfe1c286, 0x664ad8c6, 0xbfe3d70a, 0x3d70a3d2},			/* -0.55499=f(-0.62000)*/
{62, 0,123,__LINE__, 0xbfe18716, 0x10b3da3e, 0xbfe3851e, 0xb851eb80},			/* -0.54774=f(-0.61000)*/
{64, 0,123,__LINE__, 0xbfe14b1d, 0xd5f90cdd, 0xbfe33333, 0x3333332e},			/* -0.54041=f(-0.60000)*/
{64, 0,123,__LINE__, 0xbfe10e9d, 0x8cdbac44, 0xbfe2e147, 0xae147adc},			/* -0.53303=f(-0.59000)*/
{64, 0,123,__LINE__, 0xbfe0d195, 0x1a9393b2, 0xbfe28f5c, 0x28f5c28a},			/* -0.52558=f(-0.58000)*/
{64, 0,123,__LINE__, 0xbfe09404, 0x7359dee7, 0xbfe23d70, 0xa3d70a38},			/* -0.51806=f(-0.57000)*/
{64, 0,123,__LINE__, 0xbfe055eb, 0x9af3eb46, 0xbfe1eb85, 0x1eb851e6},			/* -0.51048=f(-0.56000)*/
{64, 0,123,__LINE__, 0xbfe0174a, 0xa53e6cdf, 0xbfe19999, 0x99999994},			/* -0.50284=f(-0.55000)*/
{63, 0,123,__LINE__, 0xbfdfb043, 0x6d708c01, 0xbfe147ae, 0x147ae142},			/* -0.49513=f(-0.54000)*/
{64, 0,123,__LINE__, 0xbfdf30e2, 0x0a19966b, 0xbfe0f5c2, 0x8f5c28f0},			/* -0.48735=f(-0.53000)*/
{64, 0,123,__LINE__, 0xbfdeb071, 0xaf3a3187, 0xbfe0a3d7, 0x0a3d709e},			/* -0.47951=f(-0.52000)*/
{62, 0,123,__LINE__, 0xbfde2ef3, 0x101033d6, 0xbfe051eb, 0x851eb84c},			/* -0.47161=f(-0.51000)*/
{64, 0,123,__LINE__, 0xbfddac67, 0x0561bb45, 0xbfdfffff, 0xfffffff4},			/* -0.46364=f(-0.50000)*/
{62, 0,123,__LINE__, 0xbfdd28ce, 0x8e859fe6, 0xbfdf5c28, 0xf5c28f50},			/* -0.45561=f(-0.49000)*/
{64, 0,123,__LINE__, 0xbfdca42a, 0xd266d565, 0xbfdeb851, 0xeb851eac},			/* -0.44751=f(-0.48000)*/
{60, 0,123,__LINE__, 0xbfdc1e7d, 0x2081d8d7, 0xbfde147a, 0xe147ae08},			/* -0.43936=f(-0.47000)*/
{63, 0,123,__LINE__, 0xbfdb97c6, 0xf1db4027, 0xbfdd70a3, 0xd70a3d64},			/* -0.43113=f(-0.46000)*/
{64, 0,123,__LINE__, 0xbfdb1009, 0xe9ee79b0, 0xbfdccccc, 0xccccccc0},			/* -0.42285=f(-0.45000)*/
{64, 0,123,__LINE__, 0xbfda8747, 0xd793c3d1, 0xbfdc28f5, 0xc28f5c1c},			/* -0.41450=f(-0.44000)*/
{61, 0,123,__LINE__, 0xbfd9fd82, 0xb5dc5e54, 0xbfdb851e, 0xb851eb78},			/* -0.40609=f(-0.43000)*/
{62, 0,123,__LINE__, 0xbfd972bc, 0xace3f306, 0xbfdae147, 0xae147ad4},			/* -0.39762=f(-0.42000)*/
{64, 0,123,__LINE__, 0xbfd8e6f8, 0x12962e43, 0xbfda3d70, 0xa3d70a30},			/* -0.38909=f(-0.41000)*/
{64, 0,123,__LINE__, 0xbfd85a37, 0x6b677db4, 0xbfd99999, 0x9999998c},			/* -0.38050=f(-0.40000)*/
{62, 0,123,__LINE__, 0xbfd7cc7d, 0x6affe94c, 0xbfd8f5c2, 0x8f5c28e8},			/* -0.37185=f(-0.39000)*/
{64, 0,123,__LINE__, 0xbfd73dcc, 0xf4d6fa09, 0xbfd851eb, 0x851eb844},			/* -0.36314=f(-0.38000)*/
{63, 0,123,__LINE__, 0xbfd6ae29, 0x1cbfa268, 0xbfd7ae14, 0x7ae147a0},			/* -0.35437=f(-0.37000)*/
{64, 0,123,__LINE__, 0xbfd61d95, 0x27631e9d, 0xbfd70a3d, 0x70a3d6fc},			/* -0.34555=f(-0.36000)*/
{64, 0,123,__LINE__, 0xbfd58c14, 0x8aa9c5ca, 0xbfd66666, 0x66666658},			/* -0.33667=f(-0.35000)*/
{64, 0,123,__LINE__, 0xbfd4f9aa, 0xee10ca74, 0xbfd5c28f, 0x5c28f5b4},			/* -0.32773=f(-0.34000)*/
{64, 0,123,__LINE__, 0xbfd4665c, 0x2aebeec6, 0xbfd51eb8, 0x51eb8510},			/* -0.31874=f(-0.33000)*/
{59, 0,123,__LINE__, 0xbfd3d22c, 0x4c92394e, 0xbfd47ae1, 0x47ae146c},			/* -0.30970=f(-0.32000)*/
{61, 0,123,__LINE__, 0xbfd33d1f, 0x9074c08c, 0xbfd3d70a, 0x3d70a3c8},			/* -0.30060=f(-0.31000)*/
{60, 0,123,__LINE__, 0xbfd2a73a, 0x661eaef8, 0xbfd33333, 0x33333324},			/* -0.29145=f(-0.30000)*/
{64, 0,123,__LINE__, 0xbfd21081, 0x6f1dae73, 0xbfd28f5c, 0x28f5c280},			/* -0.28225=f(-0.29000)*/
{64, 0,123,__LINE__, 0xbfd178f9, 0x7ed1f883, 0xbfd1eb85, 0x1eb851dc},			/* -0.27300=f(-0.28000)*/
{64, 0,123,__LINE__, 0xbfd0e0a7, 0x9a25599f, 0xbfd147ae, 0x147ae138},			/* -0.26371=f(-0.27000)*/
{64, 0,123,__LINE__, 0xbfd04790, 0xf72887c5, 0xbfd0a3d7, 0x0a3d7094},			/* -0.25436=f(-0.26000)*/
{57, 0,123,__LINE__, 0xbfcf5b75, 0xf92c80be, 0xbfcfffff, 0xffffffe0},			/* -0.24497=f(-0.25000)*/
{64, 0,123,__LINE__, 0xbfce2656, 0x82776e58, 0xbfceb851, 0xeb851e98},			/* -0.23554=f(-0.24000)*/
{64, 0,123,__LINE__, 0xbfccefcf, 0x168bece2, 0xbfcd70a3, 0xd70a3d50},			/* -0.22606=f(-0.23000)*/
{64, 0,123,__LINE__, 0xbfcbb7eb, 0x9ee7d2f8, 0xbfcc28f5, 0xc28f5c08},			/* -0.21655=f(-0.22000)*/
{64, 0,123,__LINE__, 0xbfca7eb8, 0x6059c7bb, 0xbfcae147, 0xae147ac0},			/* -0.20699=f(-0.21000)*/
{64, 0,123,__LINE__, 0xbfc94441, 0xf8f725ec, 0xbfc99999, 0x99999978},			/* -0.19739=f(-0.20000)*/
{64, 0,123,__LINE__, 0xbfc80895, 0x5ddac671, 0xbfc851eb, 0x851eb830},			/* -0.18776=f(-0.19000)*/
{64, 0,123,__LINE__, 0xbfc6cbbf, 0xd8acff2f, 0xbfc70a3d, 0x70a3d6e8},			/* -0.17809=f(-0.18000)*/
{64, 0,123,__LINE__, 0xbfc58dcf, 0x04f55e35, 0xbfc5c28f, 0x5c28f5a0},			/* -0.16839=f(-0.17000)*/
{64, 0,123,__LINE__, 0xbfc44ed0, 0xcd36e60b, 0xbfc47ae1, 0x47ae1458},			/* -0.15865=f(-0.16000)*/
{64, 0,123,__LINE__, 0xbfc30ed3, 0x67d7cce1, 0xbfc33333, 0x33333310},			/* -0.14888=f(-0.15000)*/
{61, 0,123,__LINE__, 0xbfc1cde5, 0x53d5fe42, 0xbfc1eb85, 0x1eb851c8},			/* -0.13909=f(-0.14000)*/
{64, 0,123,__LINE__, 0xbfc08c15, 0x5549dc61, 0xbfc0a3d7, 0x0a3d7080},			/* -0.12927=f(-0.13000)*/
{64, 0,123,__LINE__, 0xbfbe92e4, 0xe371f633, 0xbfbeb851, 0xeb851e71},			/* -0.11942=f(-0.12000)*/
{64, 0,123,__LINE__, 0xbfbc0c17, 0xd8759634, 0xbfbc28f5, 0xc28f5be2},			/* -0.10955=f(-0.11000)*/
{64, 0,123,__LINE__, 0xbfb983e2, 0x82e2cc06, 0xbfb99999, 0x99999953},			/* -0.09966=f(-0.00100)*/
{63, 0,123,__LINE__, 0xbfb6fa64, 0x46b1cb0e, 0xbfb70a3d, 0x70a3d6c4},			/* -0.08975=f(-0.09000)*/
{64, 0,123,__LINE__, 0xbfb46fbc, 0xe9dfcbbb, 0xbfb47ae1, 0x47ae1435},			/* -0.07982=f(-0.08000)*/
{64, 0,123,__LINE__, 0xbfb1e40c, 0x8b780f98, 0xbfb1eb85, 0x1eb851a6},			/* -0.06988=f(-0.07000)*/
{64, 0,123,__LINE__, 0xbfaeaee7, 0x34b5dc99, 0xbfaeb851, 0xeb851e2d},			/* -0.05992=f(-0.06000)*/
{64, 0,123,__LINE__, 0xbfa99425, 0x97929e9b, 0xbfa99999, 0x9999990e},			/* -0.04995=f(-0.05000)*/
{64, 0,123,__LINE__, 0xbfa47816, 0x23768ccb, 0xbfa47ae1, 0x47ae13ef},			/* -0.03997=f(-0.04000)*/
{62, 0,123,__LINE__, 0xbf9eb5f6, 0x44234a6b, 0xbf9eb851, 0xeb851da0},			/* -0.02999=f(-0.03000)*/
{64, 0,123,__LINE__, 0xbf947a2e, 0x5daffdee, 0xbf947ae1, 0x47ae1362},			/* -0.01999=f(-0.02000)*/
{64, 0,123,__LINE__, 0xbf847ab4, 0x8b1ef92b, 0xbf847ae1, 0x47ae1249},			/* -0.00999=f(-0.00010)*/
{64, 0,123,__LINE__, 0x3cd19000, 0x00000000, 0x3cd19000, 0x00000000},			/* 9.74915e-16=f(9.74915e-16)*/
{62, 0,123,__LINE__, 0x3f847ab4, 0x8b1efd8f, 0x3f847ae1, 0x47ae16ad},			/* 0.00999=f(0.01000)*/
{64, 0,123,__LINE__, 0x3f947a2e, 0x5db0001f, 0x3f947ae1, 0x47ae1594},			/* 0.01999=f(0.02000)*/
{64, 0,123,__LINE__, 0x3f9eb5f6, 0x44234c9d, 0x3f9eb851, 0xeb851fd2},			/* 0.02999=f(0.03000)*/
{64, 0,123,__LINE__, 0x3fa47816, 0x23768de3, 0x3fa47ae1, 0x47ae1508},			/* 0.03997=f(0.04000)*/
{64, 0,123,__LINE__, 0x3fa99425, 0x97929fb4, 0x3fa99999, 0x99999a27},			/* 0.04995=f(0.05000)*/
{63, 0,123,__LINE__, 0x3faeaee7, 0x34b5ddb1, 0x3faeb851, 0xeb851f46},			/* 0.05992=f(0.06000)*/
{64, 0,123,__LINE__, 0x3fb1e40c, 0x8b781023, 0x3fb1eb85, 0x1eb85232},			/* 0.06988=f(0.07000)*/
{64, 0,123,__LINE__, 0x3fb46fbc, 0xe9dfcc46, 0x3fb47ae1, 0x47ae14c1},			/* 0.07982=f(0.08000)*/
{64, 0,123,__LINE__, 0x3fb6fa64, 0x46b1cb99, 0x3fb70a3d, 0x70a3d750},			/* 0.08975=f(0.09000)*/
{64, 0,123,__LINE__, 0x3fb983e2, 0x82e2cc91, 0x3fb99999, 0x999999df},			/* 0.09966=f(0.10000)*/
{64, 0,123,__LINE__, 0x3fbc0c17, 0xd87596bf, 0x3fbc28f5, 0xc28f5c6e},			/* 0.10955=f(0.11000)*/
{64, 0,123,__LINE__, 0x3fbe92e4, 0xe371f6be, 0x3fbeb851, 0xeb851efd},			/* 0.11942=f(0.12000)*/
{64, 0,123,__LINE__, 0x3fc08c15, 0x5549dca5, 0x3fc0a3d7, 0x0a3d70c6},			/* 0.12927=f(0.13000)*/
{64, 0,123,__LINE__, 0x3fc1cde5, 0x53d5fe87, 0x3fc1eb85, 0x1eb8520e},			/* 0.13909=f(0.14000)*/
{64, 0,123,__LINE__, 0x3fc30ed3, 0x67d7cd26, 0x3fc33333, 0x33333356},			/* 0.14888=f(0.15000)*/
{64, 0,123,__LINE__, 0x3fc44ed0, 0xcd36e650, 0x3fc47ae1, 0x47ae149e},			/* 0.15865=f(0.16000)*/
{64, 0,123,__LINE__, 0x3fc58dcf, 0x04f55e79, 0x3fc5c28f, 0x5c28f5e6},			/* 0.16839=f(0.17000)*/
{61, 0,123,__LINE__, 0x3fc6cbbf, 0xd8acff73, 0x3fc70a3d, 0x70a3d72e},			/* 0.17809=f(0.18000)*/
{64, 0,123,__LINE__, 0x3fc80895, 0x5ddac6b5, 0x3fc851eb, 0x851eb876},			/* 0.18776=f(0.19000)*/
{63, 0,123,__LINE__, 0x3fc94441, 0xf8f7262f, 0x3fc99999, 0x999999be},			/* 0.19739=f(0.20000)*/
{64, 0,123,__LINE__, 0x3fca7eb8, 0x6059c7fe, 0x3fcae147, 0xae147b06},			/* 0.20699=f(0.21000)*/
{64, 0,123,__LINE__, 0x3fcbb7eb, 0x9ee7d33b, 0x3fcc28f5, 0xc28f5c4e},			/* 0.21655=f(0.22000)*/
{64, 0,123,__LINE__, 0x3fccefcf, 0x168bed26, 0x3fcd70a3, 0xd70a3d96},			/* 0.22606=f(0.23000)*/
{64, 0,123,__LINE__, 0x3fce2656, 0x82776e9a, 0x3fceb851, 0xeb851ede},			/* 0.23554=f(0.24000)*/
{64, 0,123,__LINE__, 0x3fcf5b75, 0xf92c8102, 0x3fd00000, 0x00000013},			/* 0.24497=f(0.25000)*/
{64, 0,123,__LINE__, 0x3fd04790, 0xf72887e6, 0x3fd0a3d7, 0x0a3d70b7},			/* 0.25436=f(0.26000)*/
{63, 0,123,__LINE__, 0x3fd0e0a7, 0x9a2559c0, 0x3fd147ae, 0x147ae15b},			/* 0.26371=f(0.27000)*/
{61, 0,123,__LINE__, 0x3fd178f9, 0x7ed1f8a4, 0x3fd1eb85, 0x1eb851ff},			/* 0.27300=f(0.28000)*/
{64, 0,123,__LINE__, 0x3fd21081, 0x6f1dae93, 0x3fd28f5c, 0x28f5c2a3},			/* 0.28225=f(0.29000)*/
{64, 0,123,__LINE__, 0x3fd2a73a, 0x661eaf18, 0x3fd33333, 0x33333347},			/* 0.29145=f(0.30000)*/
{61, 0,123,__LINE__, 0x3fd33d1f, 0x9074c0aa, 0x3fd3d70a, 0x3d70a3eb},			/* 0.30060=f(0.31000)*/
{64, 0,123,__LINE__, 0x3fd3d22c, 0x4c92396e, 0x3fd47ae1, 0x47ae148f},			/* 0.30970=f(0.32000)*/
{64, 0,123,__LINE__, 0x3fd4665c, 0x2aebeee6, 0x3fd51eb8, 0x51eb8533},			/* 0.31874=f(0.33000)*/
{64, 0,123,__LINE__, 0x3fd4f9aa, 0xee10ca93, 0x3fd5c28f, 0x5c28f5d7},			/* 0.32773=f(0.34000)*/
{63, 0,123,__LINE__, 0x3fd58c14, 0x8aa9c5e8, 0x3fd66666, 0x6666667b},			/* 0.33667=f(0.35000)*/
{64, 0,123,__LINE__, 0x3fd61d95, 0x27631ebc, 0x3fd70a3d, 0x70a3d71f},			/* 0.34555=f(0.36000)*/
{63, 0,123,__LINE__, 0x3fd6ae29, 0x1cbfa286, 0x3fd7ae14, 0x7ae147c3},			/* 0.35437=f(0.37000)*/
{64, 0,123,__LINE__, 0x3fd73dcc, 0xf4d6fa28, 0x3fd851eb, 0x851eb867},			/* 0.36314=f(0.38000)*/
{64, 0,123,__LINE__, 0x3fd7cc7d, 0x6affe96b, 0x3fd8f5c2, 0x8f5c290b},			/* 0.37185=f(0.39000)*/
{63, 0,123,__LINE__, 0x3fd85a37, 0x6b677dd3, 0x3fd99999, 0x999999af},			/* 0.38050=f(0.40000)*/
{62, 0,123,__LINE__, 0x3fd8e6f8, 0x12962e60, 0x3fda3d70, 0xa3d70a53},			/* 0.38909=f(0.41000)*/
{63, 0,123,__LINE__, 0x3fd972bc, 0xace3f325, 0x3fdae147, 0xae147af7},			/* 0.39762=f(0.42000)*/
{64, 0,123,__LINE__, 0x3fd9fd82, 0xb5dc5e72, 0x3fdb851e, 0xb851eb9b},			/* 0.40609=f(0.43000)*/
{63, 0,123,__LINE__, 0x3fda8747, 0xd793c3ef, 0x3fdc28f5, 0xc28f5c3f},			/* 0.41450=f(0.44000)*/
{59, 0,123,__LINE__, 0x3fdb1009, 0xe9ee79d0, 0x3fdccccc, 0xcccccce3},			/* 0.42285=f(0.45000)*/
{63, 0,123,__LINE__, 0x3fdb97c6, 0xf1db4044, 0x3fdd70a3, 0xd70a3d87},			/* 0.43113=f(0.46000)*/
{64, 0,123,__LINE__, 0x3fdc1e7d, 0x2081d8f4, 0x3fde147a, 0xe147ae2b},			/* 0.43936=f(0.47000)*/
{64, 0,123,__LINE__, 0x3fdca42a, 0xd266d583, 0x3fdeb851, 0xeb851ecf},			/* 0.44751=f(0.48000)*/
{62, 0,123,__LINE__, 0x3fdd28ce, 0x8e85a002, 0x3fdf5c28, 0xf5c28f73},			/* 0.45561=f(0.49000)*/
{64, 0,123,__LINE__, 0x3fddac67, 0x0561bb61, 0x3fe00000, 0x0000000b},			/* 0.46364=f(0.50000)*/
{64, 0,123,__LINE__, 0x3fde2ef3, 0x101033ef, 0x3fe051eb, 0x851eb85d},			/* 0.47161=f(0.51000)*/
{64, 0,123,__LINE__, 0x3fdeb071, 0xaf3a31a2, 0x3fe0a3d7, 0x0a3d70af},			/* 0.47951=f(0.52000)*/
{62, 0,123,__LINE__, 0x3fdf30e2, 0x0a199684, 0x3fe0f5c2, 0x8f5c2901},			/* 0.48735=f(0.53000)*/
{63, 0,123,__LINE__, 0x3fdfb043, 0x6d708c1b, 0x3fe147ae, 0x147ae153},			/* 0.49513=f(0.54000)*/
{64, 0,123,__LINE__, 0x3fe0174a, 0xa53e6cec, 0x3fe19999, 0x999999a5},			/* 0.50284=f(0.55000)*/
{64, 0,123,__LINE__, 0x3fe055eb, 0x9af3eb52, 0x3fe1eb85, 0x1eb851f7},			/* 0.51048=f(0.56000)*/
{64, 0,123,__LINE__, 0x3fe09404, 0x7359def4, 0x3fe23d70, 0xa3d70a49},			/* 0.51806=f(0.57000)*/
{64, 0,123,__LINE__, 0x3fe0d195, 0x1a9393c0, 0x3fe28f5c, 0x28f5c29b},			/* 0.52558=f(0.58000)*/
{64, 0,123,__LINE__, 0x3fe10e9d, 0x8cdbac50, 0x3fe2e147, 0xae147aed},			/* 0.53303=f(0.59000)*/
{64, 0,123,__LINE__, 0x3fe14b1d, 0xd5f90cea, 0x3fe33333, 0x3333333f},			/* 0.54041=f(0.60000)*/
{64, 0,123,__LINE__, 0x3fe18716, 0x10b3da4a, 0x3fe3851e, 0xb851eb91},			/* 0.54774=f(0.61000)*/
{64, 0,123,__LINE__, 0x3fe1c286, 0x664ad8d2, 0x3fe3d70a, 0x3d70a3e3},			/* 0.55499=f(0.62000)*/
{64, 0,123,__LINE__, 0x3fe1fd6f, 0x0de97390, 0x3fe428f5, 0xc28f5c35},			/* 0.56218=f(0.63000)*/
{64, 0,123,__LINE__, 0x3fe237d0, 0x4c1eae0a, 0x3fe47ae1, 0x47ae1487},			/* 0.56931=f(0.64000)*/
{64, 0,123,__LINE__, 0x3fe271aa, 0x72553edd, 0x3fe4cccc, 0xccccccd9},			/* 0.57637=f(0.65000)*/
{64, 0,123,__LINE__, 0x3fe2aafd, 0xde4d0ca7, 0x3fe51eb8, 0x51eb852b},			/* 0.58337=f(0.66000)*/
{64, 0,123,__LINE__, 0x3fe2e3ca, 0xf9964226, 0x3fe570a3, 0xd70a3d7d},			/* 0.59030=f(0.67000)*/
{64, 0,123,__LINE__, 0x3fe31c12, 0x390e2a02, 0x3fe5c28f, 0x5c28f5cf},			/* 0.59717=f(0.68000)*/
{64, 0,123,__LINE__, 0x3fe353d4, 0x1c5dfe70, 0x3fe6147a, 0xe147ae21},			/* 0.60398=f(0.69000)*/
{64, 0,123,__LINE__, 0x3fe38b11, 0x2d7bd4b6, 0x3fe66666, 0x66666673},			/* 0.61072=f(0.70000)*/
{64, 0,123,__LINE__, 0x3fe3c1ca, 0x002dc87f, 0x3fe6b851, 0xeb851ec5},			/* 0.61740=f(0.71000)*/
{64, 0,123,__LINE__, 0x3fe3f7ff, 0x318f872b, 0x3fe70a3d, 0x70a3d717},			/* 0.62402=f(0.72000)*/
{64, 0,123,__LINE__, 0x3fe42db1, 0x679a5777, 0x3fe75c28, 0xf5c28f69},			/* 0.63057=f(0.73000)*/
{64, 0,123,__LINE__, 0x3fe462e1, 0x50afb668, 0x3fe7ae14, 0x7ae147bb},			/* 0.63707=f(0.74000)*/
{64, 0,123,__LINE__, 0x3fe4978f, 0xa3269ee9, 0x3fe80000, 0x0000000d},			/* 0.64350=f(0.75000)*/
{64, 0,123,__LINE__, 0x3fe4cbbd, 0x1cdb8e78, 0x3fe851eb, 0x851eb85f},			/* 0.64987=f(0.76000)*/
{64, 0,123,__LINE__, 0x3fe4ff6a, 0x82c35607, 0x3fe8a3d7, 0x0a3d70b1},			/* 0.65617=f(0.77000)*/
{64, 0,123,__LINE__, 0x3fe53298, 0xa080c394, 0x3fe8f5c2, 0x8f5c2903},			/* 0.66242=f(0.78000)*/
{64, 0,123,__LINE__, 0x3fe56548, 0x47fd2e08, 0x3fe947ae, 0x147ae155},			/* 0.66861=f(0.79000)*/
{64, 0,123,__LINE__, 0x3fe5977a, 0x5103ea9a, 0x3fe99999, 0x999999a7},			/* 0.67474=f(0.80000)*/
{64, 0,123,__LINE__, 0x3fe5c92f, 0x98e0b079, 0x3fe9eb85, 0x1eb851f9},			/* 0.68080=f(0.81000)*/
{64, 0,123,__LINE__, 0x3fe5fa69, 0x0200ed4d, 0x3fea3d70, 0xa3d70a4b},			/* 0.68681=f(0.82000)*/
{64, 0,123,__LINE__, 0x3fe62b27, 0x73980b19, 0x3fea8f5c, 0x28f5c29d},			/* 0.69276=f(0.83000)*/
{64, 0,123,__LINE__, 0x3fe65b6b, 0xd946a623, 0x3feae147, 0xae147aef},			/* 0.69865=f(0.84000)*/
{64, 0,123,__LINE__, 0x3fe68b37, 0x22c4afbc, 0x3feb3333, 0x33333341},			/* 0.70449=f(0.85000)*/
{64, 0,123,__LINE__, 0x3fe6ba8a, 0x438e792e, 0x3feb851e, 0xb851eb93},			/* 0.71027=f(0.86000)*/
{64, 0,123,__LINE__, 0x3fe6e966, 0x3294a09f, 0x3febd70a, 0x3d70a3e5},			/* 0.71599=f(0.87000)*/
{64, 0,123,__LINE__, 0x3fe717cb, 0xe9eed85b, 0x3fec28f5, 0xc28f5c37},			/* 0.72165=f(0.88000)*/
{64, 0,123,__LINE__, 0x3fe745bc, 0x66917fb7, 0x3fec7ae1, 0x47ae1489},			/* 0.72726=f(0.89000)*/
{64, 0,123,__LINE__, 0x3fe77338, 0xa80603c6, 0x3feccccc, 0xccccccdb},			/* 0.73281=f(0.90000)*/
{64, 0,123,__LINE__, 0x3fe7a041, 0xb025fcf0, 0x3fed1eb8, 0x51eb852d},			/* 0.73831=f(0.91000)*/
{64, 0,123,__LINE__, 0x3fe7ccd8, 0x82d8fdc5, 0x3fed70a3, 0xd70a3d7f},			/* 0.74375=f(0.92000)*/
{64, 0,123,__LINE__, 0x3fe7f8fe, 0x25d50682, 0x3fedc28f, 0x5c28f5d1},			/* 0.74914=f(0.93000)*/
{64, 0,123,__LINE__, 0x3fe824b3, 0xa0619021, 0x3fee147a, 0xe147ae23},			/* 0.75448=f(0.94000)*/
{64, 0,123,__LINE__, 0x3fe84ff9, 0xfb1d2135, 0x3fee6666, 0x66666675},			/* 0.75976=f(0.95000)*/
{64, 0,123,__LINE__, 0x3fe87ad2, 0x3fc55e4e, 0x3feeb851, 0xeb851ec7},			/* 0.76499=f(0.96000)*/
{64, 0,123,__LINE__, 0x3fe8a53d, 0x79018731, 0x3fef0a3d, 0x70a3d719},			/* 0.77017=f(0.97000)*/
{64, 0,123,__LINE__, 0x3fe8cf3c, 0xb22f51ed, 0x3fef5c28, 0xf5c28f6b},			/* 0.77529=f(0.98000)*/
{64, 0,123,__LINE__, 0x3fe8f8d0, 0xf732146f, 0x3fefae14, 0x7ae147bd},			/* 0.78037=f(0.99000)*/
{64, 0,123,__LINE__, 0x3fe921fb, 0x54442d1f, 0x3ff00000, 0x00000007},			/* 0.78539=f(1.00000)*/
{64, 0,123,__LINE__, 0x3fe94abc, 0xd5ca9ad6, 0x3ff028f5, 0xc28f5c30},			/* 0.79037=f(1.01000)*/
{64, 0,123,__LINE__, 0x3fe97316, 0x882ab461, 0x3ff051eb, 0x851eb859},			/* 0.79529=f(1.02000)*/
{64, 0,123,__LINE__, 0x3fe99b09, 0x77a1efcd, 0x3ff07ae1, 0x47ae1482},			/* 0.80017=f(1.03000)*/
{64, 0,123,__LINE__, 0x3fe9c296, 0xb01fa9ac, 0x3ff0a3d7, 0x0a3d70ab},			/* 0.80500=f(1.04000)*/
{64, 0,123,__LINE__, 0x3fe9e9bf, 0x3d20dc77, 0x3ff0cccc, 0xccccccd4},			/* 0.80978=f(1.05000)*/
{64, 0,123,__LINE__, 0x3fea1084, 0x298db881, 0x3ff0f5c2, 0x8f5c28fd},			/* 0.81451=f(1.06000)*/
{64, 0,123,__LINE__, 0x3fea36e6, 0x7f990cbc, 0x3ff11eb8, 0x51eb8526},			/* 0.81920=f(1.07000)*/
{64, 0,123,__LINE__, 0x3fea5ce7, 0x48a17105, 0x3ff147ae, 0x147ae14f},			/* 0.82384=f(1.08000)*/
{64, 0,123,__LINE__, 0x3fea8287, 0x8d14229d, 0x3ff170a3, 0xd70a3d78},			/* 0.82843=f(1.09000)*/
{64, 0,123,__LINE__, 0x3feaa7c8, 0x545183d3, 0x3ff19999, 0x999999a1},			/* 0.83298=f(1.10000)*/
{64, 0,123,__LINE__, 0x3feaccaa, 0xa4932ff4, 0x3ff1c28f, 0x5c28f5ca},			/* 0.83748=f(1.11000)*/
{64, 0,123,__LINE__, 0x3feaf12f, 0x82d394fc, 0x3ff1eb85, 0x1eb851f3},			/* 0.84194=f(1.12000)*/
{64, 0,123,__LINE__, 0x3feb1557, 0xf2b704ae, 0x3ff2147a, 0xe147ae1c},			/* 0.84635=f(1.13000)*/
{64, 0,123,__LINE__, 0x3feb3924, 0xf6762efe, 0x3ff23d70, 0xa3d70a45},			/* 0.85072=f(1.14000)*/
{64, 0,123,__LINE__, 0x3feb5c97, 0x8ec9f80c, 0x3ff26666, 0x6666666e},			/* 0.85505=f(1.15000)*/
{64, 0,123,__LINE__, 0x3feb7fb0, 0xbad89c41, 0x3ff28f5c, 0x28f5c297},			/* 0.85933=f(1.16000)*/
{64, 0,123,__LINE__, 0x3feba271, 0x78241558, 0x3ff2b851, 0xeb851ec0},			/* 0.86357=f(1.17000)*/
{64, 0,123,__LINE__, 0x3febc4da, 0xc279b37f, 0x3ff2e147, 0xae147ae9},			/* 0.86778=f(1.18000)*/
{64, 0,123,__LINE__, 0x3febe6ed, 0x93e2de10, 0x3ff30a3d, 0x70a3d712},			/* 0.87193=f(1.19000)*/
{64, 0,123,__LINE__, 0xbff69b81, 0x54baf42e, 0xc01921fb, 0x54442d18},			/* -1.41296=f(-6.28318)*/
{64, 0,123,__LINE__, 0xbff5c97d, 0x37d98aa3, 0xc012d97c, 0x7f3321d2},			/* -1.36169=f(-4.71238)*/
{64, 0,123,__LINE__, 0xbff433b8, 0xa322ddd2, 0xc00921fb, 0x54442d18},			/* -1.26262=f(-3.14159)*/
{64, 0,123,__LINE__, 0xbff00fe9, 0x87ed02ff, 0xbff921fb, 0x54442d18},			/* -1.00388=f(-1.57079)*/
{64, 0,123,__LINE__, 0x00000000, 0x00000000, 0x00000000, 0x00000000},			/* 0.00000=f(0.00000)*/
{64, 0,123,__LINE__, 0x3ff00fe9, 0x87ed02ff, 0x3ff921fb, 0x54442d18},			/* 1.00388=f(1.57079)*/
{64, 0,123,__LINE__, 0x3ff433b8, 0xa322ddd2, 0x400921fb, 0x54442d18},			/* 1.26262=f(3.14159)*/
{64, 0,123,__LINE__, 0x3ff5c97d, 0x37d98aa3, 0x4012d97c, 0x7f3321d2},			/* 1.36169=f(4.71238)*/
{64, 0,123,__LINE__, 0xbff8997f, 0xbb8b19c0, 0xc03e0000, 0x00000000},			/* -1.53747=f(-30.0000)*/
{64, 0,123,__LINE__, 0xbff8914e, 0x9558e14d, 0xc03c4ccc, 0xcccccccd},			/* -1.53547=f(-28.3000)*/
{64, 0,123,__LINE__, 0xbff88811, 0xbbe6dd19, 0xc03a9999, 0x9999999a},			/* -1.53322=f(-26.6000)*/
{64, 0,123,__LINE__, 0xbff87d92, 0x7628865c, 0xc038e666, 0x66666667},			/* -1.53065=f(-24.9000)*/
{64, 0,123,__LINE__, 0xbff8718a, 0x0c21772b, 0xc0373333, 0x33333334},			/* -1.52772=f(-23.2000)*/
{64, 0,123,__LINE__, 0xbff8639b, 0x79e21172, 0xc0358000, 0x00000001},			/* -1.52431=f(-21.5000)*/
{64, 0,123,__LINE__, 0xbff85349, 0xe792c6df, 0xc033cccc, 0xccccccce},			/* -1.52033=f(-19.8000)*/
{64, 0,123,__LINE__, 0xbff83fe9, 0xca4b0fb2, 0xc0321999, 0x9999999b},			/* -1.51560=f(-18.1000)*/
{64, 0,123,__LINE__, 0xbff82888, 0xd516330c, 0xc0306666, 0x66666668},			/* -1.50989=f(-16.4000)*/
{64, 0,123,__LINE__, 0xbff80bc5, 0x5b9fbf46, 0xc02d6666, 0x6666666a},			/* -1.50287=f(-14.7000)*/
{64, 0,123,__LINE__, 0xbff7e786, 0x2aa0157c, 0xc02a0000, 0x00000004},			/* -1.49402=f(-13.0000)*/
{64, 0,123,__LINE__, 0xbff7b872, 0x197c1745, 0xc0269999, 0x9999999e},			/* -1.48253=f(-11.3000)*/
{64, 0,123,__LINE__, 0xbff778d9, 0x2c06c36f, 0xc0233333, 0x33333338},			/* -1.46700=f(-9.60000)*/
{64, 0,123,__LINE__, 0xbff71e3e, 0x5f2c979f, 0xc01f9999, 0x999999a3},			/* -1.44488=f(-7.90000)*/
{64, 0,123,__LINE__, 0xbff692fa, 0x44218618, 0xc018cccc, 0xccccccd6},			/* -1.41088=f(-6.20000)*/
{64, 0,123,__LINE__, 0xbff5a250, 0x52114e62, 0xc0120000, 0x00000009},			/* -1.35212=f(-4.50000)*/
{64, 0,123,__LINE__, 0xbff3a4f4, 0xa8668b6d, 0xc0066666, 0x66666678},			/* -1.22777=f(-2.80000)*/
{64, 0,123,__LINE__, 0xbfeaa7c8, 0x545183ed, 0xbff19999, 0x999999bd},			/* -0.83298=f(-1.10000)*/
{64, 0,123,__LINE__, 0x3fe14b1d, 0xd5f90cac, 0x3fe33333, 0x333332ec},			/* 0.54041=f(0.60000)*/
{64, 0,123,__LINE__, 0x3ff29219, 0xa497099b, 0x40026666, 0x66666654},			/* 1.16066=f(2.30000)*/
{64, 0,123,__LINE__, 0x3ff5368c, 0x951e9cfa, 0x400fffff, 0xffffffee},			/* 1.32581=f(4.00000)*/
{64, 0,123,__LINE__, 0x3ff65a9f, 0xe0f20774, 0x4016cccc, 0xccccccc4},			/* 1.39712=f(5.70000)*/
{64, 0,123,__LINE__, 0x3ff6fbcd, 0x16bebe3f, 0x401d9999, 0x99999991},			/* 1.43647=f(7.40000)*/
{64, 0,123,__LINE__, 0x3ff761ab, 0xb0d2ec50, 0x40223333, 0x3333332f},			/* 1.46134=f(9.10000)*/
{64, 0,123,__LINE__, 0x3ff7a7cd, 0x013209a5, 0x40259999, 0x99999995},			/* 1.47846=f(10.8000)*/
{64, 0,123,__LINE__, 0x3ff7daff, 0x85a63058, 0x4028ffff, 0xfffffffb},			/* 1.49096=f(12.5000)*/
{64, 0,123,__LINE__, 0x3ff80201, 0xa882c932, 0x402c6666, 0x66666661},			/* 1.50049=f(14.2000)*/
{64, 0,123,__LINE__, 0x3ff820b5, 0xe69c2ec6, 0x402fcccc, 0xccccccc7},			/* 1.50798=f(15.9000)*/
{64, 0,123,__LINE__, 0x3ff83981, 0x22b99e8c, 0x40319999, 0x99999997},			/* 1.51403=f(17.6000)*/
{64, 0,123,__LINE__, 0x3ff84df1, 0x81e40544, 0x40334ccc, 0xccccccca},			/* 1.51902=f(19.3000)*/
{64, 0,123,__LINE__, 0x3ff85f14, 0xd43d81be, 0x4034ffff, 0xfffffffd},			/* 1.52321=f(21.0000)*/
{64, 0,123,__LINE__, 0x3ff86da8, 0x6687209e, 0x4036b333, 0x33333330},			/* 1.52677=f(22.7000)*/
{64, 0,123,__LINE__, 0x3ff87a34, 0xf080f2f8, 0x40386666, 0x66666663},			/* 1.52983=f(24.4000)*/
{64, 0,123,__LINE__, 0x3ff8851f, 0xa51ef694, 0x403a1999, 0x99999996},			/* 1.53250=f(26.1000)*/
{64, 0,123,__LINE__, 0x3ff88eb5, 0x0616141e, 0x403bcccc, 0xccccccc9},			/* 1.53484=f(27.8000)*/
{64, 0,123,__LINE__, 0x3ff8972f, 0xfc482372, 0x403d7fff, 0xfffffffc},			/* 1.53691=f(29.5000)*/
0,};
test_atan(m)   {run_vector_1(m,atan_vec,(char *)(atan),"atan","dd");   }	
