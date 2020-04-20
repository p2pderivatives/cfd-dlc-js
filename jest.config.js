module.exports = {
  transform: {
    "^.+\\.ts?$": "ts-jest",
  },
  globals: {
    "ts-jest": {
      tsConfig: "tsconfig.json",
    },
  },
  testMatch: ["<rootDir>/wrap_js/__test__/*.spec.ts"],
};
