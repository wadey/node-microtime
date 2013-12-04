
exports.now = function () {
  var hrTime = process.hrtime();
  return (((hrTime[0] * 1000000000) + hrTime[1]) * 1000);
};
exports.nowDouble = function () {
  var hrTime = process.hrtime();
  return (hrTime[0] + (hrTime[1] / 1000000000.0));
};
exports.nowStruct = function () {
  var hrTime = process.hrtime();
  return [hrTime[0], (hrTime[1] * 1000)];
};
