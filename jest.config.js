module.exports = {
  transform: {
    "^.+\\.ts?$": "ts-jest",
  },
  globals: {
    "ts-jest": {
      tsconfig: "tsconfig.json",
    },
  },
  testMatch: ["<rootDir>/wrap_js/__test__/*.spec.ts"],
};
